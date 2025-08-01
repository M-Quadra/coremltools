#ifndef MLMODEL_GLOBALS_HPP
#define MLMODEL_GLOBALS_HPP

#include <memory>
#include <string>
#include <vector>

#include "DataType.hpp"

#define MLMODEL_SPECIFICATION_VERSION MLMODEL_SPECIFICATION_VERSION_NEWEST

namespace CoreML {

    typedef std::vector<std::pair<std::string, FeatureType>> SchemaType;
    // Version 1 shipped as iOS 11.0
    static const int32_t MLMODEL_SPECIFICATION_VERSION_IOS11 = 1;
    // Version 2 supports fp16 weights and custom layers in neural network models. Shipped in iOS 11.2
    static const int32_t MLMODEL_SPECIFICATION_VERSION_IOS11_2 = 2;

    // Version 3 supports:
    // - custom models
    // - flexible sizes,
    // - Categorical sequences (string, int64),
    // - Word tagger
    // - Text classifier
    // - Vision feature print
    // - New neural network layers (resizeBilinear, cropResize)
    // - <fill in as we develop> ..
    static const int32_t MLMODEL_SPECIFICATION_VERSION_IOS12 = 3;

    // Version 4 supports:
    // - New NN layers, non rank 5 tensors
    // - Updatable models
    // - Exact shape / general rank mapping for neural networks
    // - Large expansion of supported neural network layers
    //   - Generalized operations
    //   - Control flow
    //   - Dynamic layers
    //   - See NeuralNetwork.proto
    // - Nearest Neighbor Classifier
    // - Sound Analysis Prepreocessing
    // - Recommender
    // - Linked Model
    static const int32_t MLMODEL_SPECIFICATION_VERSION_IOS13 = 4;

    // version 5:
    // - New NN layers part of the proto message "NeuralNetworkLayer"
    // - Non-Zero default values for optional inputs in case of Neural Networks
    // - Float32 input/output for NonmaximumSuppression model
    static const int32_t MLMODEL_SPECIFICATION_VERSION_IOS14 = 5;

    // version 6:
    // - New "mlProgram" model type
    // - Sound Print of Audio Feature Print
    static const int32_t MLMODEL_SPECIFICATION_VERSION_IOS15 = 6;

    // version 7:
    // - FLOAT16 array data type
    // - GRAYSCALE_FLOAT16 image color space.
    static const int32_t MLMODEL_SPECIFICATION_VERSION_IOS16 = 7;

    // version 8:
    static const int32_t MLMODEL_SPECIFICATION_VERSION_IOS17 = 8;

    // version 9:
    static const int32_t MLMODEL_SPECIFICATION_VERSION_IOS18 = 9;

    // version 10:
    static const int32_t MLMODEL_SPECIFICATION_VERSION_IOS26 = 10;

    static const int32_t MLMODEL_SPECIFICATION_VERSION_NEWEST = MLMODEL_SPECIFICATION_VERSION_IOS26;

}

#endif
