#pragma once

#include <string>
#include <vector>

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };

struct Product {
  std::string name;
  Color color;
  Size size;
};

// struct ProductFilter {

//     typedef std::vector<Product*> Items;

//     static Items by_color(Items items, Color color) {
//         Items result;
//         for (auto& i : items) {
//             if (i->color == color)
//                 result.push_back(i);
//         }
//         return result;
//     }

// };

template <typename T>
struct ISpecification {
  virtual bool is_satisfied(T* item) = 0;
};

template <typename T>
struct IFilter {
  virtual std::vector<T*> filter(std::vector<T*> items,
                                 ISpecification<T>& spec) = 0;
};

struct ProductFilter : IFilter<Product> {
  typedef std::vector<Product*> Products;

  Products filter(Products items, ISpecification<Product>& spec) override {
    Products result;
    for (auto& p : items) {
      if (spec.is_satisfied(p)) result.push_back(p);
    }
    return result;
  }
};

struct ColorSpecification : ISpecification<Product> {
  Color color;

  explicit ColorSpecification(const Color color) : color{color} {}

  bool is_satisfied(Product* item) override { return item->color == color; }
};

struct SizeSpecification : ISpecification<Product> {
  Size size;

  explicit SizeSpecification(const Size size) : size{size} {}

  bool is_satisfied(Product* item) override { return item->size == size; }
};

template <typename T>
struct AndSpecification : ISpecification<Product> {
  ISpecification& first;
  ISpecification& second;

  AndSpecification(ISpecification& first, ISpecification& second)
      : first{first}, second{second} {}

  bool is_satisfied(T* item) override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};