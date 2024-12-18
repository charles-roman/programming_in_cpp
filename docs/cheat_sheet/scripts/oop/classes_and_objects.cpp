// CLASSES & OBJECTS

/* A class is a user-defined data type and a template for objects. An object is an instance of a class.

    Classes hold data members and member functions which can be accessed by objects of the class

    Classes are built in .hpp files (including member function declaration), but member functions
    (including constructor/destructor) should be defined in the related .cpp file, although they
    can be defined inside the class as well 
*/

    // Defining Classes (in .hpp file)
        class MyClass {                         

            type my_attribute;		                    // class attribute (private scope, class members are private by default) 

            public:					                    // access specifier (scope is available to all code)

                MyClass(type param=default_val, ...);   // declare constructor(s)

                ~MyClass();	                            // declare destructor 

                MyClass(MyClass& oldObj);               // declare copy constructor
                MyClass& operator=(MyClass&);           // declare copy assignment operator

                MyClass(MyClass&& myObj);               // declare move constructor
                MyClass& operator=(MyClass&&);          // declare move assignment operator

                type& operator[](type);                 // declare other operator functions (ex.)

                type getValue();                        // declare accessor function
                void setValue(type new_variable);       // declare mutator function

                type my_function(type param);	        // declare member function

                type my_variable;                       // declare data member (class attribute)
                mutable type my_value;                  // can be modified even in case of const object
                type *my_data;                          // dynamically allocated; makes resource transfers non-trivial

            protected:				                    // access specifier (scope is within class and subclasses) 

                // protected code;

            private:	                                // access specifier (scope is within class only)
                                                        // ...for explicitly defining more private material under public scope
                // private code; 	             

        };

    
    /* 
        All member functions (including constructors/destructors) created inside class are inline by default,
        functions defined outside require inline specifier
    */

    // Constructors (in .cpp file)
        /* 
            used to create objects (instances) of a class
            called by compiler everytime an object of the class is instantiated 
        */

        MyClass::MyClass() {                            // default constructor (provided by compiler implicitly if NO constructors defined)
            // constructor code                                             // (best practice to define explicitly)                      
        }                                                            

        MyClass::MyClass(param, ...)                    // parameterized constructor (can provide default args to params so it acts as default constructor as well)
            : my_attribute(param)... {}                 // member initializer list (must use for const and reference attributes!)...
                                                        // ...also best to use for init class members (especially for classes with heavy constructors)

        MyClass::MyClass(param, ...) {	                // alternate definition of parameterized constructor 
            my_attribute = param; 
        }

        MyClass::MyClass(const MyClass& myObj) {        // copy constructor (compiler creates implicit definition if no explicit definition)
            ...                                         // ... typically needed when an object contains pointers or non-shareable refs
            my_data = new type;
            *my_data = *myObj.my_data;
        }

        MyClass::MyClass(MyClass&& myObj) noexcept {    // move constructor (compiler creates implicit definition if no explicit definition)
            ...                                         // ... useful for efficiently transferring ownership of resources (less overhead)
            my_data = myObj.my_data; 
            myObj.my_data = nullptr;
        }

    // Destructors (in .cpp file)
        /* 
            used to destroy (release memory) objects of a class

            called by compiler if...
            1) object out of scope
            2) object explicitly deleted
            3) program ends

            cannot be overloaded
            cannot be declared static or const
            does not take any inputs or return anything
            called in reverse order of constructor invocations

            generally if constructor allocates memory on the heap or class contains some other dynamically allocated memory,
            destructor should be defined to free that memory
        */

        MyClass::~MyClass() {   // destructor (compiler creates implicit definition if no explicit definition)
            // destructor code 
        }

    // Operators (in .cpp file)
        MyClass& MyClass::operator=(const MyClass& myObj) {         // copy assignment operator
            if (this != &myObj) {
                delete my_data;
                my_data = new type;
                *my_data = *myObj.my_data;
            }
            return *this;
        }

        MyClass& MyClass::operator=(MyClass&& myObj) noexcept {     // move assignment operator
            if (this != &myObj) {
                delete my_data;
                my_data = myObj.my_data;
                myObj.my_data = nullptr;
            }
            return *this;
        }                                                           

        type MyClass::operator[](type param) { }                    // other operators (ex. w/ [])

    /* 
        Rule of 5: if one of the following special functions is created in a class, all should be created in the class 
        Destructor, Copy constructor, Copy assignment operator, Move constructor, Move assignment operator
    */

    /*
        Compiler creates implicit definitions of: 
            Default Constructor
            Copy Constructor
            Move Constructor
            Copy Assignment Operator
            Move Assignment Operator
            Destructor
                                    (if not defined explicitly)
            
            *Defining any copy/move constructor or operator
            will cause the compiler to not implictly define
            any of the other 3
                            
    */

        // Special member function modifiers
        =default;   // explicitly defaulted function (requests compiler to generate default version)
        =delete;    // explicitly deleted function (prevents compiler from generating implicit defs)
        noexcept    // specifies that a function does not throw exceptions (useful for optimization)
        explicit    // prevents implicit conversions and copy-initialization for constructors (and conversion operators)
                    // gold rule: use for all constructors which can be called with 1 arg provided

    // Defining Member Functions (in .cpp file)
        type MyClass::getValue() const {			// accessor function 
            return my_variable; 
        } 

        void MyClass::setValue(type new_variable) {	// mutator function 
            my_variable = new_variable; 
        }

        type MyClass::my_function(param) {	        // define member function 
            return my_attribute;		            // class attributes are in scope for member functions
        }

    // Defining SubClass
        class SubClass: public BaseClass {	        // Inheritance (subclass or derived class inherits from superclass or baseclass) 
            // class code 
        };

    // Function Specifiers
        const type my_function() {}         // ensures the returned value cannot be modified (can be useful for ptrs/refs) 
        type my_function() const {}         // guarantees function will not modify state of object (non-static data members)
        virtual type my_function() {}       // declares member function as virtual, allowing it to be overriden in derived classes
        type my_function() override {}      // specifies that a member function is intended to override a base class function
        virtual type my_function() final {} // prevents a virtual function from being overridden in derived classes
        explicit my_function() {}           // specifies that a constructor or conversion operator should not be implicitly invoked
        static type my_function() {}        // specifies that a member fxn doesn't operate on instance of class & can be called w/out obj
        constexpr type my_function() {}     // indicates that the func can produce a constant expression & can be evaluated @ compile time
        friend type my_function() {}        // allows a non-member function to access the private and protected members of the class 

    // Create and Manipulate Objects (and Class Attributes)
        MyClass myObject;		                 // instantiate object of class (must have valid default constructor!)
        MyClass myObject(args);	                 // instantiate object with attributes (implicitly)
        MyClass myObject = MyClass(args);        // instantiate object with attributes (explicitly)

        MyClass newObject(myObject);             // instantiate object from another object (copy)
        MyClass newObject = myObject;            // instantiate object from another object (copy, alternate syntax)
        MyClass newObject(std::move(myObject));  // instantiate object from another object (move)

        MyClass.my_attribute = 0;	             // assign attribute value 

        myObject.my_variable = 0;                // modify data member of object
        myObject.my_function();	                 // call function of class on object

        myObject.~MyClass();                     // destroy object 

    // OOP Core Concepts
        /*
            Encapsulation – bundling related data/functions within limited data scope (consolidate) 

            Abstraction – hiding complex logic and making code more accessible (simplify) 

            Inheritance – classes inheriting attributes and functions of other classes (reuse) 

            Polymorphism – same entities can operate differently under different situations (interchange)
        */


       