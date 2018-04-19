#pragma once

#include <iostream>
#include <vector>

struct Neuron {
  std::vector<Neuron*> in, out;
  unsigned int id;

  Neuron() {
    static int id = 1;
    this->id = id++;
  }

  void connect_to(Neuron& other) {
    out.push_back(&other);
    other.in.push_back(this);
  }
};

struct NeuronLayer : std::vector<Neuron> {
  NeuronLayer(int count) {
    while (count-- > 0) {
      emplace_back(Neuron());
    }
  }
};