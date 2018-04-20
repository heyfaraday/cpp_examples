#pragma once

#include <iostream>
#include <vector>

struct Neuron {
  std::vector<Neuron*> in, out;
  unsigned int id;

  Neuron* begin() { return this; }
  Neuron* end() { return this + 1; }

  Neuron() {
    static int id = 1;
    this->id = id++;
  }

  void connect_to(Neuron& other) {
    out.push_back(&other);
    other.in.push_back(this);
  }

  template <typename T>
  void connect_to(T& other) {
    for (Neuron& to : other) {
      connect_to(to);
    }
  }
};

struct NeuronLayer : std::vector<Neuron> {
  NeuronLayer(int count) {
    while (count-- > 0) {
      emplace_back(Neuron());
    }
  }

  template <typename T>
  void connect_to(T& other) {
    for (Neuron& from : *this) {
      for (Neuron& to : other) {
        from.connect_to(to);
      }
    }
  }
};