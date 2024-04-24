package java_final_review;

public class polymorphism {
    /*
     * Basically, if you have some classes that extend a base class, you can use the base class
     * to refer to any of the derived classes (not runtime polymorphism)
     * 
     * Runtime polymorphism is when you can declare a general class and then initialize it later with
     * some derived class and use it as an instance of the derived class
     * 
     * Abstract and implement
     * Can be explained as a contract between the class and whats derived from it
     * If you have a method that implements another method, you have to implement everything that 
     * that method implements (protocol in swift) (called an interface in java)
     * 
     * To define an abstract class you use the abstract keyword
     * abstract methods are methods that are declared but not implemented and the derived class must implement them
     * 
     * Now I was mistaken and an interface is actually its own thing
     * That is basically a definition template for a class and now this is like a protocol in swift
     * 
     * Now Implements is what you add to a class to tell it you are implementing that interface so that it can
     * help you implement everything you need so you dont get lost
     * 
     * difference between abstract and interface
     *  - abstract can have both abstract and non abstract methods whereas interface can only have abstract methods
     *  - abstract can have final, static, or static final variables, interface can only have static final 
     *  - abstract: extends, interface: implements
     *  - abstract: members are free to be whatever, interface: members are public by default
     *  - interfaces are usually very short
     *  - derived class can only inherit one abstract class but can implements has multiple interfacess
     */
}
