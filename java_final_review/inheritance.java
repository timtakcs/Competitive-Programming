package java_final_review;

public class inheritance {
    // is-a relationship

    /*
     * The extended class can grab public methods from the super class
     * final keyword makes it impossible for the derived class to override the original var or method
     * Access modifiers
     *  - public is everyone (literally)
     *  - private is not accessible in the subclass (only via accessor method)
     *  - protected means you have access to it iff you are a subclass
     *  - protected final means you have access to it iff you are a subclass but you can't override it
     * 
     * The derived class must have a constructor as well
     *  - it can be called using the super() method
     * 
     * Apparently C++ lets you have default constructors with no parameters, all constructors you use
     * have to be explicitly defined
     * 
     * Overriding is basically just declaring a method with the same name in the subclass with different paremeters
     * (different from overloading)
     * 
     */
}
