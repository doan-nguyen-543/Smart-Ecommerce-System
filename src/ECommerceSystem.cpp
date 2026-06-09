#include "ECommerceSystem.h"

#include <iostream>
#include <limits>
#include <ctime>

using namespace std;

ECommerceSystem::ECommerceSystem()
    : recommender(&productManager),
      statistics(&productManager, &userManager),
      nextOrderId(1001)
{
    productManager.loadProducts("data/products.txt");
    userManager.loadUsers();
    orderManager.loadOrders("data/orders.txt");
    nextOrderId = 1003;
}

void ECommerceSystem::run()
{
    int choice;

    do
    {
        cout << "\n========== E-COMMERCE SYSTEM ==========\n";
        cout << "1. Login\n";
        cout << "2. Register Customer\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string username;
            string password;

            cout << "Username: ";
            cin >> username;

            cout << "Password: ";
            cin >> password;

            User* user = userManager.login(username, password);

            if (!user)
            {
                cout << "Invalid username or password!\n";
                break;
            }

            if (Admin* admin = dynamic_cast<Admin*>(user))
            {
                adminMenu(admin);
            }
            else if (Customer* customer =
                         dynamic_cast<Customer*>(user))
            {
                customerMenu(customer);
            }

            break;
        }

        case 2:
        {
            string username;
            string password;

            cout << "New username: ";
            cin >> username;

            cout << "New password: ";
            cin >> password;

            if (userManager.registerCustomer(username, password))
            {
                cout << "Registration successful!\n";
                userManager.saveUsers();
            }
            else
            {
                cout << "Registration failed!\n";
            }

            break;
        }

        case 0:
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    productManager.saveProducts("data/products.txt");
    userManager.saveUsers();
    orderManager.saveOrders("data/orders.txt");
}

//Custom Menu
void ECommerceSystem::customerMenu(Customer* customer)
{
    int choice;

    do
    {
        cout << "\n========== CUSTOMER MENU ==========\n";
        cout << "1. View Products\n";
        cout << "2. View Recommendations\n";
        cout << "3. View Cart\n";
        cout << "4. Checkout\n";
        cout << "5. Order History\n";
        cout << "0. Logout\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            productManager.displayProducts();

            int productID;

            cout << "\nEnter Product ID to purchase (0 to cancel): ";
            cin >> productID;

            if (productID == 0)
                break;

            Product* product =
                productManager.findProduct(productID);

            if (!product)
            {
                cout << "Product not found!\n";
                break;
            }

            customer->browseProducts(product);

            int qty;

            cout << "Quantity to add to cart: ";
            cin >> qty;

            if (qty > 0)
            {
                customer->addToCart(product, qty);
                cout << "Added to cart.\n";
            }

            break;
        }

        case 2:
        {
            vector<Product> top =
                recommender.getTopRecommendations();

            cout << "\n===== TOP RECOMMENDATIONS =====\n";

            for (const auto& p : top)
            {
                p.display();
            }

            break;
        }

        case 3:
        {
            customer->getCart().displayCart();
            break;
        }

        case 4:
        {
            const vector<CartItem>& cartItems =
                customer->getCart().getItems();

            if (cartItems.empty())
            {
                cout << "Cart is empty.\n";
                break;
            }

            time_t now = time(nullptr);
            tm* localTime = localtime(&now);
            char dateBuf[11];
            strftime(dateBuf, sizeof(dateBuf), "%Y-%m-%d", localTime);

            Order order(
                nextOrderId++,
                customer->getID(),
                cartItems,
                dateBuf
            );

            orderManager.createOrder(order);
            customer->checkout();
            cout << "Checkout completed.\n";
            break;
        }

        case 5:
        {
            vector<Order> orders =
                orderManager.getCustomerOrders(customer->getID());

            if (orders.empty())
            {
                cout << "No orders found.\n";
                break;
            }

            for (const Order& order : orders)
            {
                order.displayOrder();
                cout << "----------------------\n";
            }

            break;
        }

        case 0:
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}

//Admin Menu
void ECommerceSystem::adminMenu(Admin* admin)
{
    int choice;

    do
    {
        cout << "\n========== ADMIN MENU ==========\n";
        cout << "1. View Products\n";
        cout << "2. Add Product\n";
        cout << "3. Delete Product\n";
        cout << "4. Statistics\n";
        cout << "5. View Orders\n";
        cout << "0. Logout\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            productManager.displayProducts();
            break;
        }

        case 2:
        {
            int id;
            string name;
            string category;
            double price;
            int stock;

            cout << "ID: ";
            cin >> id;

            cin.ignore();

            cout << "Name: ";
            getline(cin, name);

            cout << "Category: ";
            getline(cin, category);

            cout << "Price: ";
            cin >> price;

            cout << "Stock: ";
            cin >> stock;

            Product p(
                id,
                name,
                category,
                price,
                stock
            );

            productManager.addProduct(p);

            cout << "Product added.\n";

            break;
        }

        case 3:
        {
            int id;

            cout << "Product ID: ";
            cin >> id;

            if (productManager.deleteProduct(id))
            {
                cout << "Deleted.\n";
            }
            else
            {
                cout << "Product not found.\n";
            }

            break;
        }

        case 4:
        {
            statistics.getMostViewedProducts();
            statistics.getBestSellingProducts();
            statistics.getActiveUsers();
            break;
        }

        case 5:
        {
            orderManager.displayAllOrders();
            break;
        }

        case 0:
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}