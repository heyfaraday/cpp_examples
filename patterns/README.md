## Software design patterns ([wiki](https://en.wikipedia.org/wiki/Software_design_pattern))

### Decorator pattern ([wiki](https://en.wikipedia.org/wiki/Decorator_pattern))
* Aggregate objects
* Can aggregate more than one
  * E.g., string, and formatting
* Replicate the APIs you want (e.g., length)
* Miss out on the APIs you don't need
* Add your own features :)

### Composite pattern ([wiki](https://en.wikipedia.org/wiki/Composite_pattern))

### Specification pattern ([wiki](https://en.wikipedia.org/wiki/Specification_pattern))
* Simple filtering solution is
  * Too difficult to maintain, violates OCP
  * Not flexible enough
* Abstract away the specification interface
  * bool is_satisfied_by(T something)
* Abstract away the idea of filtering
  * Input items + specification -> set of filtered items
* Create combinations (e.g., AndSpecification) for combining multiple specifications

### Builder pattern ([wiki](https://en.wikipedia.org/wiki/Builder_pattern))

### Memento pattern ([wiki](https://en.wikipedia.org/wiki/Memento_pattern))
* Helping implement undo/redo
* Bank account
  * Bank account has a balance
  * Balance changed via
    * Withdrawals
    * Deposits
  * Want to be able to undo an erroneous transaction
  * Want to navigate to an arbitrary point in the account's changeset
* Memento (a.k.a. Token, Cookie)
  * Keeps the state of the balance at a particular point in time
    * State is typically private
  * Can also keep the reason for the latest change, amount, etc.
  * Returned during bank account changes
  * Memento can be used to restore the object to a particular state

### Observer pattern ([wiki](https://en.wikipedia.org/wiki/Observer_pattern))
* Simple model
  * Person has an age: private field with accessor/mutator
  * We want to be informed whenever age changes
  * Need to modify the setter!

