#include <iostream>

#include "header.hpp"

int main(int argc, char *argv[]) {
  Neuron first;
  Neuron second;

  NeuronLayer first_layer(100);
  NeuronLayer second_layer(200);

  first.connect_to(second);
  first.connect_to(first_layer);

  first_layer.connect_to(first);
  first_layer.connect_to(second_layer);

  return 0;
}