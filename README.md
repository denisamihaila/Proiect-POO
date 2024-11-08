# 🛒 Online Store - Object-Oriented Programming Project


## Overview

Welcome to the **Online Store** project! This application is designed as part of an Object-Oriented Programming (OOP) project in C++, showcasing essential OOP principles and techniques. This project models a simplified online store, allowing users to browse products, manage their shopping cart, log in, and proceed to checkout.

The project demonstrates OOP concepts such as **encapsulation**, **inheritance**, and **polymorphism** while implementing practical functionality relevant to e-commerce applications.

## 📑 Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Concepts and Techniques Used](#concepts-and-techniques-used)
- [Usage](#usage)
- [Code Highlights](#code-highlights)
- [Future Improvements](#future-improvements)

---

## 🚀 Features

- **Product Catalog**: Users can view available products with details such as price, description, and stock status.
- **User Authentication**: Users can log in to access personalized features and maintain shopping session.
- **Shopping Cart Management**: Add, update, or remove items from the shopping cart.
- **Checkout Process**: Simulate a checkout process with basic validation and order summary.
- **Exception Handling**: Robust error management to handle invalid inputs and system exceptions gracefully.
- **Scalability**: Modular design allows for easy extension of features.

---

## 📂 Project Structure

The project is organized into multiple classes, each representing key components of an online store.

### 🔹 Utilized Classes

- **`Produs`**: Defines the attributes and methods of a product, including constructors, setters, getters, and overloading of I/O operators.
- **`Haina`**: Inherits from `Produs`, representing clothing items with an additional attribute for material.
- **`Utilizator`**: Manages user data such as username, personal information, email, password, and budget.
- **`LogIn`**: Handles user login and account creation processes.
- **`Magazin`, `MagazinClient`, `MagazinVanzator`**: Abstract and derived classes that encapsulate the different functionalities of the store depending on the user type (customer or seller).
- **`MagazinAdmin`**: Completes diamond inheritance along with the three classes above. It introduces an additional feature — the ability to delete products. Additionally, the `cumpără()` function had two different implementations in the two classes it directly inherits from, so it was necessary to specify which implementation should be called.

Each class follows OOP principles, ensuring modular, reusable, and easily extensible code.

### 🔸 Main Program

The main program (`main.cpp`) initializes classes and controls the application’s flow:
1. **Login**: Allows the user to authenticate and access features.
2. **Display Product List**: Lists all products for the user.
3. **Cart Operations**: Users can add, modify, or remove products in their cart.
4. **Checkout**: Provides a summary of the order and validates the transaction.

---

## 📐 Concepts and Techniques Used

In this project, several advanced programming concepts and patterns were implemented to enhance functionality, maintainability, and flexibility. Here are some of the key techniques used:

### 🏗️ Design Patterns
- **Singleton Pattern**: Ensures a single instance of the `LogIn` class, managing user authentication and session.
- **Factory Method Pattern**: Used in `ProdusFactory` and `HainaFactory` to create different types of products dynamically.
- **Strategy Pattern**: Enables flexible pricing strategies. Implemented with `PretStrategy` as the base strategy, and specific strategies like `PretStandardStrategy` and `PretReducereStrategy`.

### 🧩 Template Classes and Functions
- **Template Class**: `Catalog` is designed as a template class to allow flexibility in the types of products it can store and manage.
- **Template Function**: `void printCollection()` is a template function for printing collections, making it versatile for various container types.

### 📚 Standard Template Library (STL)
The project makes extensive use of the C++ Standard Template Library (STL) for efficient data handling:
- **Containers**: `string`, `map`, `vector`, `list` are used to store and manipulate data.
- **Algorithms**: Functions from the `<algorithm>` library, such as `find`, `find_if`, `remove_if`, and `move`, are used to process collections efficiently.

### 🧠 Smart Pointers
To manage memory dynamically and prevent memory leaks, the project uses smart pointers:
- **`shared_ptr`**: Used for instances of `produs`, `haina`, and `catalog` to share ownership of resources across multiple parts of the program.
- **`unique_ptr`**: Used for `PretStrategy` and `LogIn` instances, ensuring unique ownership and avoiding unintended duplication.

### 🔄 Additional Techniques
- **Const-Correctness**: `const` is applied wherever possible to ensure that data remains unmodified when it should be read-only, enhancing code safety and reliability.
- **Exception Handling**: `try-catch` blocks are implemented throughout the code to handle potential runtime errors and enhance user experience by providing clear feedback in case of invalid inputs or operations.

### 🔍 Other Notable Features
- **Overloading and Operator Overloading**: Custom operators are implemented for specific classes, improving usability and readability.
- **Inheritance and Polymorphism**: Core OOP principles, including polymorphic behavior through virtual functions, allow the project to manage different product types and user roles efficiently.

---

## 📝 Usage

Once the program is running, the user can navigate through a series of options to simulate shopping online. Follow the on-screen prompts to explore features.

### Example Flow

1. **Login**: Authenticate to access the online store features.
2. **Browse Products**: Review the available items with details like price and stock.
3. **Add to Cart**: Select products and add them to your shopping cart.
4. **Review Cart**: View items in the cart, update quantities, or remove items.
5. **Checkout**: Finalize the purchase, review order details, and confirm.

---

## ✨ Code Highlights

This project emphasizes several C++ and OOP best practices:

1. **Encapsulation**: Each class hides its data and only exposes necessary methods, ensuring data integrity.
2. **Inheritance and Polymorphism**: Different classes inherit from base classes and override methods where needed, allowing for flexible and reusable code.
3. **Error Handling**: Try-catch blocks handle invalid input and other runtime exceptions, improving the user experience.
4. **Efficiency**: Code is structured to minimize redundancy and optimize performance, ensuring smooth execution.

---

## 🔧 Future Improvements

Potential extensions for this project include:

* **Database Integration**: Store product data and user orders in a database to maintain persistent data.
* **GUI Interface**: Shift from a console-based application to a graphical user interface for a more user-friendly experience.


