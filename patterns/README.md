## Software design patterns ([wiki](https://en.wikipedia.org/wiki/Software_design_pattern))

### Decorator pattern ([wiki](https://en.wikipedia.org/wiki/Decorator_pattern))
* Aggregate objects
* Can aggregate more than one
  * E.g., string and formatting
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
