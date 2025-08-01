#ifndef MLMODEL_DECLARE_TEST
#define MLMODEL_DECLARE_TEST(x) int x();
#endif

#ifdef MLMODEL_RUN_TEST
#define MLMODEL_TEST(x) MLMODEL_RUN_TEST(x)
#else
#define MLMODEL_TEST(x) MLMODEL_DECLARE_TEST(x)
#endif

MLMODEL_TEST(testBasicSaveLoad)
MLMODEL_TEST(testLinearModelBasic)
MLMODEL_TEST(testTreeEnsembleBasic)
MLMODEL_TEST(testOneHotEncoderBasic)
MLMODEL_TEST(testLargeModel)
MLMODEL_TEST(testVeryLargeModel)
MLMODEL_TEST(testOptionalInputs)
MLMODEL_TEST(testFeatureDescriptions)

MLMODEL_TEST(testNNValidatorLoop)
MLMODEL_TEST(testNNValidatorMissingInput)
MLMODEL_TEST(testNNValidatorSimple)
MLMODEL_TEST(testNNValidatorMissingOutput)
MLMODEL_TEST(testNNValidatorBadInputs)
MLMODEL_TEST(testNNValidatorBadInput)
MLMODEL_TEST(testNNValidatorBadInput2)
MLMODEL_TEST(testNNValidatorBadOutput)
MLMODEL_TEST(testNNValidatorBadOutput2)
MLMODEL_TEST(testNNMissingLayer)
MLMODEL_TEST(testInnerProductDynamicQuantizationConversionParameterValidation)
MLMODEL_TEST(testBatchedMatMulDynamicQuantizationConversionParameterValidation)
MLMODEL_TEST(testRNNLayer)
MLMODEL_TEST(testRNNLayer2)
MLMODEL_TEST(testNNValidatorAllOptional)
MLMODEL_TEST(testNNValidatorReshape3D)
MLMODEL_TEST(testNNValidatorReshape4D)
MLMODEL_TEST(testNNValidatorReshapeBad)
MLMODEL_TEST(testNNCompilerValidation)
MLMODEL_TEST(testNNCompilerValidationGoodProbBlob)
MLMODEL_TEST(testNNCompilerValidationBadProbBlob)
MLMODEL_TEST(testInvalidPooling)
MLMODEL_TEST(testValidPooling3d)
MLMODEL_TEST(testInvalidPooling3dNegativeKernelSize)
MLMODEL_TEST(testInvalidPooling3dCostumPaddingSetForNonCustomPaddingType)
MLMODEL_TEST(testValidGlobalPooling3d)
MLMODEL_TEST(testInvalidGlobalPooling3dWrongNumberOfInputs)
MLMODEL_TEST(testInvalidConvolutionNoPadding)
MLMODEL_TEST(testInvalidConvolutionNoWeights)
MLMODEL_TEST(testInvalidConvolutionNoBias)
MLMODEL_TEST(testValidConvolution)
MLMODEL_TEST(testValidDeconvolution)
MLMODEL_TEST(testInvalidConvolution3DNegativePadding)
MLMODEL_TEST(testInvalidConvolution3DNoBias)
MLMODEL_TEST(testInvalidConvolution3DNoInputChannels)
MLMODEL_TEST(testInvalidConvolution3DNoOutputChannels)
MLMODEL_TEST(testInvalidConvolution3DNoWeights)
MLMODEL_TEST(testInvalidConvolution3DNonPositiveDilation)
MLMODEL_TEST(testInvalidConvolution3DNonPositiveGroups)
MLMODEL_TEST(testInvalidConvolution3DNonPositiveKernelSize)
MLMODEL_TEST(testInvalidConvolution3DNonPositiveStride)
MLMODEL_TEST(testInvalidConvolution3DTwoInputs)
MLMODEL_TEST(testInvalidConvolution3DWithOutputShape)
MLMODEL_TEST(testValidConvolution3D)
MLMODEL_TEST(testInvalidDeConvolution3DOutputShape)
MLMODEL_TEST(testValidDeConvolution3D)
MLMODEL_TEST(testInvalidEmbedding)
MLMODEL_TEST(testInvalidEmbeddingBias)
MLMODEL_TEST(testValidEmbedding)
MLMODEL_TEST(testInvalidBatchnorm)
MLMODEL_TEST(testValidComputeMeanVarBatchnorm)
MLMODEL_TEST(testInvalidPaddingBorder)
MLMODEL_TEST(testInvalidPaddingNoType)
MLMODEL_TEST(testValidPadding)
MLMODEL_TEST(testInvalidUpsample)
MLMODEL_TEST(testInvalidUpsampleNearestNeighborsModeWithAlignCorners)
MLMODEL_TEST(testValidUpsample)
MLMODEL_TEST(testFractionalUpsample)
MLMODEL_TEST(testValidUpsampleAlignCorners)
MLMODEL_TEST(testUpsampleArgsortSpec)
MLMODEL_TEST(testInvalidScaleBiasWeights)
MLMODEL_TEST(testInvalidScaleWeights)
MLMODEL_TEST(testInvalidScaleBiasLength)
MLMODEL_TEST(testInvalidScaleLength)
MLMODEL_TEST(testValidScale)
MLMODEL_TEST(testValidScaleNoBias)
MLMODEL_TEST(testValidCrop1)
MLMODEL_TEST(testInvalidCrop1)
MLMODEL_TEST(testValidCrop2)
MLMODEL_TEST(testInvalidCrop2)
MLMODEL_TEST(testInvalidCrop3)
MLMODEL_TEST(testInvalidSlice)
MLMODEL_TEST(testValidSlice1)
MLMODEL_TEST(testValidSlice2)
MLMODEL_TEST(testValidCustom)
MLMODEL_TEST(testInvalidCustomNoName)
MLMODEL_TEST(testInvalidCustomMultipleWeights)
MLMODEL_TEST(testVisionFeatureScenePrintBasic)
MLMODEL_TEST(testVisionFeatureObjectPrintBasic)
MLMODEL_TEST(testAudioFeatureSoundPrintBasic)
MLMODEL_TEST(testVggishPreprocessingBasic)
MLMODEL_TEST(testSpecDowngrade)
MLMODEL_TEST(testSpecDowngradefp16)
MLMODEL_TEST(testSpecDowngradeFlexibleShapes)
MLMODEL_TEST(testSpecDowngradeFlexibleShapes2)
MLMODEL_TEST(testSpecDowngradePipeline)
MLMODEL_TEST(testWordTaggerTransferLearningSpecIOS14)
MLMODEL_TEST(testEmptyInputModel_downgradeToIOS18)
MLMODEL_TEST(testMultiFunctionModel_downgradeToIOS18)
MLMODEL_TEST(testBayesianProbitRegressionValidationBasic)
MLMODEL_TEST(testRangeVal)
MLMODEL_TEST(testRangeValDivide)
MLMODEL_TEST(testShapeRange)
MLMODEL_TEST(testSimpleNNShape)
MLMODEL_TEST(testSimpleNNShapeBad)
MLMODEL_TEST(testSimpleNNShapeBadOutput)
MLMODEL_TEST(testSimple1DConv)
MLMODEL_TEST(testPermuteShape)
MLMODEL_TEST(testUpwardPass)
MLMODEL_TEST(testSamePaddingConvolution)
MLMODEL_TEST(testSamePaddingConvolution2)
MLMODEL_TEST(testValidSoftmax)
MLMODEL_TEST(testInvalidRank)
MLMODEL_TEST(testInvalidSoftmax)
MLMODEL_TEST(testInvalidSoftmax2)
MLMODEL_TEST(testInvalidReduce)
MLMODEL_TEST(testValidReduce)
MLMODEL_TEST(testValidTransposeND)
MLMODEL_TEST(testInvalidTransposeNdNoAxis)
MLMODEL_TEST(testKNNValidatorNoPoints)
MLMODEL_TEST(testKNNValidatorNoK)
MLMODEL_TEST(testKNNValidatorNoDimension)
MLMODEL_TEST(testKNNValidatorNoLabels)
MLMODEL_TEST(testKNNValidatorWrongNumberOfLabels)
MLMODEL_TEST(testKNNValidatorNoIndex)
MLMODEL_TEST(testKNNValidatorLinearIndex)
MLMODEL_TEST(testKNNValidatorSingleKdTreeIndex)
MLMODEL_TEST(testKNNValidatorNoWeightingScheme)
MLMODEL_TEST(testKNNValidatorNoDistanceFunction)
MLMODEL_TEST(testInvalidDefaultOptionalValue)
MLMODEL_TEST(testDefaultOptionalValueZeroIfNotSet)
MLMODEL_TEST(testDefaultOptionalValueOnUnsupportedSpec)
MLMODEL_TEST(testDefaultOptionalValueGood)
MLMODEL_TEST(testKNNValidatorGood)
MLMODEL_TEST(testEmptyKNNValidationGood)
MLMODEL_TEST(testLabelTypeMismatchTest)
MLMODEL_TEST(testNumberOfNeighborsWithDefaultValueInRange)
MLMODEL_TEST(testNumberOfNeighborsWithDefaultValueOutOfRange)
MLMODEL_TEST(testNumberOfNeighborsWithDefaultValueInSet)
MLMODEL_TEST(testNumberOfNeighborsWithDefaultValueNotInSet)
MLMODEL_TEST(testNumberOfNeighborsWithInvalidRange)
MLMODEL_TEST(testNumberOfNeighborsWithInvalidSet)
MLMODEL_TEST(testValidReorganizeData)
MLMODEL_TEST(testInvalidReorganizeDataInputRank)
MLMODEL_TEST(testInvalidReorganizeDataBlockSize)

MLMODEL_TEST(testValidBranch)
MLMODEL_TEST(testInvalidBranchOutputNotProduced1)
MLMODEL_TEST(testInvalidBranchOutputNotProduced2)
MLMODEL_TEST(testInvalidBranchBlobOverwrite)
MLMODEL_TEST(testInvalidCopy)
MLMODEL_TEST(testInvalidLoop1)
MLMODEL_TEST(testInvalidLoop2)
MLMODEL_TEST(testInvalidLoop3)
MLMODEL_TEST(testInvalidLoop4)
MLMODEL_TEST(testInvalidLoop5)
MLMODEL_TEST(testInvalidLoopBreak)
MLMODEL_TEST(testInvalidLoopContinue)
MLMODEL_TEST(testInvalidRankInconsistency)
MLMODEL_TEST(testInvalidExpandDims1)
MLMODEL_TEST(testInvalidExpandDims2)
MLMODEL_TEST(testInvalidSqueeze1)
MLMODEL_TEST(testInvalidPoolingRank1)
MLMODEL_TEST(testInvalidPoolingRank2)
MLMODEL_TEST(testInvalidIOS13LayerOldRank)
MLMODEL_TEST(testInvalidConcatNdWrongAxis)
MLMODEL_TEST(testInvalidSoftmaxNdWrongAxis)
MLMODEL_TEST(testInvalidSlidingWindowWrongAxis)
MLMODEL_TEST(testInvalidReverseWrongDimLength)
MLMODEL_TEST(testInvalidStackWrongAxis)
MLMODEL_TEST(testInvalidSplitNdNoSplitSizesAndNumSplits)
MLMODEL_TEST(testInvalidSplitNdWrongNumSplits)
MLMODEL_TEST(testInvalidSplitNdWrongAxis)
MLMODEL_TEST(testInvalidFillStaticNoTargetShape)
MLMODEL_TEST(testInvalidBroadcastToStaticNoTargetShape)
MLMODEL_TEST(testInvalidSliceStaticNoParams)
MLMODEL_TEST(testInvalidClipWrongMinMax)
MLMODEL_TEST(testInvalidFlattenTo2dWrongAxis)
MLMODEL_TEST(testInvalidReshapeStaticNoTargetShape)
MLMODEL_TEST(testInvalidRandomUniformDistributionWrongMinMax)
MLMODEL_TEST(testInvalidRandomBernoulliDistributionWrongProb)
MLMODEL_TEST(testInvalidReductionTypeWrongAxis)
MLMODEL_TEST(testInvalidLayerNormalizationNoNormalizedShape)
MLMODEL_TEST(testInvalidLayerNormalizationNoGammaOrBeta)
MLMODEL_TEST(testInvalidLayerNormalizationWrongGammaOrBeta)
MLMODEL_TEST(testInvalidConstantPad)
MLMODEL_TEST(testInvalidArgsortWrongAxis)

// multi-function tests
MLMODEL_TEST(testMultiFunctionSpecificationVersion)
MLMODEL_TEST(testMultiFunctionDefaultFunctionName)
MLMODEL_TEST(testMultiFunctionTopLevelFeatureDescriptionsMustBeEmpty)
MLMODEL_TEST(testMultiFunctionEmptyInput)
MLMODEL_TEST(testMultiFunctionAllowed)

// stateful prediction tests
MLMODEL_TEST(testStateSpecificationVersion)
MLMODEL_TEST(testStateFeatureDescriptionInInputs)
MLMODEL_TEST(testStateFeatureIsNotFP16_shouldFail)
MLMODEL_TEST(testStateFeatureIsOptional_shouldFail)
MLMODEL_TEST(testStateFeatureHasNoDefaultShape_shouldFail)
MLMODEL_TEST(testStateFeatureHasNoArrayType_shouldFail)
MLMODEL_TEST(testStateFeature_ArrayUsesRangeFlexibleShape_shouldFail)
MLMODEL_TEST(testStateFeature_ArrayUsesEnumeratedFlexibleShape_shouldFail)

// Int8 multi-array tests
MLMODEL_TEST(testArrayFeature_Int8_SpecificationVersion)
MLMODEL_TEST(testArrayFeature_DefaultOptionalValueOutOfRange_shouldFail)

// Updatable model tests
MLMODEL_TEST(testUpdatableModelSpecVersion)
MLMODEL_TEST(testInvalidUpdatableModelQuantizedWeights)
MLMODEL_TEST(testInvalidUpdatableModelQuantizedBias)
MLMODEL_TEST(testValidUpdatableModelQuantizedWeightsAndBiasForNonUpdatableLayer)
MLMODEL_TEST(testInvalidUpdatableModelWrongType)
MLMODEL_TEST(testInvalidUpdatableModelWrongLayer)
MLMODEL_TEST(testInvalidUpdatableModelWrongWeights)
MLMODEL_TEST(testInvalidUpdatableModelWrongBiases)
MLMODEL_TEST(testInvalidUpdatableModelNonUpdatableLayers)
MLMODEL_TEST(testInvalidUpdatableModelwithCollidedLayerAndLossLayerNames)
MLMODEL_TEST(testInvalidModelUnsupportedLayersForBP)
MLMODEL_TEST(testInvalidUpdatableLayerMissingBias)
MLMODEL_TEST(testInvalidCategoricalCrossEntropyLossLayerInputs)
MLMODEL_TEST(testInvalidMeanSquaredErrorLossLayerInputs)
MLMODEL_TEST(testInvalidModelInvalidSoftmax)
MLMODEL_TEST(testValidModelValidMultipleSoftmax_1)
MLMODEL_TEST(testValidModelValidMultipleSoftmax_2)
MLMODEL_TEST(testValidModelMultipleSoftmaxOutputs)
MLMODEL_TEST(testInvalidModelMultipleLoss)
MLMODEL_TEST(testMissingUpdatableModelParameters)
MLMODEL_TEST(testMissingMiniBatchSizeParameter)
MLMODEL_TEST(testMissingLearningRateParameter)
MLMODEL_TEST(testMissingBeta1Parameter)
MLMODEL_TEST(testMissingBeta2Parameter)
MLMODEL_TEST(testMissingEpsParameter)
MLMODEL_TEST(testMissingEpochsParameter)
MLMODEL_TEST(testValidUpdatableModelWith1024Layers)
MLMODEL_TEST(testExistingShuffleWithMissingSeedParameter)

// Pipeline tests
MLMODEL_TEST(testNonUpdatablePipelineWithNonUpdatableModels)
MLMODEL_TEST(testNonUpdatablePipelineWithOneUpdatableModel)
MLMODEL_TEST(testNonUpdatablePipelineWithOneUpdatableModelInsidePipelineHierarchy)
MLMODEL_TEST(testUpdatablePipelineWithNonUpdatableModels)
MLMODEL_TEST(testUpdatablePipelineWithMultipleUpdatableModels)
MLMODEL_TEST(testUpdatablePipelineWithOneUpdatableModel)
MLMODEL_TEST(testUpdatablePipelineWithOneUpdatableModelInsidePipelineHierarchy)

// Parameter tests
MLMODEL_TEST(testMiniBatchSizeOutOfAllowedRange)
MLMODEL_TEST(testMiniBatchSizeOutOfAllowedSet)
MLMODEL_TEST(testLearningRateOutOfAllowedRange)
MLMODEL_TEST(testMomentumOutOfAllowedRange)
MLMODEL_TEST(testBeta1OutOfAllowedRange)
MLMODEL_TEST(testBeta2OutOfAllowedRange)
MLMODEL_TEST(testEpsOutOfAllowedRange)
MLMODEL_TEST(testEpochsOutOfAllowedRange)
MLMODEL_TEST(testEpochsOutOfAllowedSet)

//
// MILBlob storage tests and support infrastructure
// #begin milblob
MLMODEL_TEST(testFileWriterTestsNoAccess)
MLMODEL_TEST(testFileWriterTestsOffsetNotAligned)
MLMODEL_TEST(testFileWriterTestsReadData)
MLMODEL_TEST(testFileWriterTestsWriteDataWithOffset)
MLMODEL_TEST(testFileWriterTestsWriteToFile)
MLMODEL_TEST(testMMapFileReaderTestsFileErrorEmpty)
MLMODEL_TEST(testMMapFileReaderTestsFileErrorNotFound)
MLMODEL_TEST(testMMapFileReaderTestsReadData)
MLMODEL_TEST(testMMapFileReaderTestsReadStruct)
MLMODEL_TEST(testSpanCastTestsBasics)
MLMODEL_TEST(testSpanCastTestsFromInt4)
MLMODEL_TEST(testSpanCastTestsToInt4)
MLMODEL_TEST(testSpanTestsAccessImmutable)
MLMODEL_TEST(testSpanTestsAccessMutable)
MLMODEL_TEST(testSpanTestsConstInt4)
MLMODEL_TEST(testSpanTestsConstUInt4)
MLMODEL_TEST(testSpanTestsCopyAndAssignment)
MLMODEL_TEST(testSpanTestsDefaultConstructor)
MLMODEL_TEST(testSpanTestsEmpty)
MLMODEL_TEST(testSpanTestsImplicitConstCopyCtor)
MLMODEL_TEST(testSpanTestsInt4)
MLMODEL_TEST(testSpanTestsIterationDynamicSlices)
MLMODEL_TEST(testSpanTestsIterationIllegal)
MLMODEL_TEST(testSpanTestsIterationMultipleDims)
MLMODEL_TEST(testSpanTestsIterationStaticSlices)
MLMODEL_TEST(testSpanTestsIteratorImmutable)
MLMODEL_TEST(testSpanTestsIteratorImmutableExplicitBeginEnd)
MLMODEL_TEST(testSpanTestsIteratorImmutableExplicitCRBeginCREnd)
MLMODEL_TEST(testSpanTestsIteratorImmutableExplicitCbeginCend)
MLMODEL_TEST(testSpanTestsIteratorImmutableExplicitRBeginREnd)
MLMODEL_TEST(testSpanTestsIteratorMutable)
MLMODEL_TEST(testSpanTestsIteratorMutableExplicitBeginEnd)
MLMODEL_TEST(testSpanTestsIteratorMutableExplicitCRbeginCRend)
MLMODEL_TEST(testSpanTestsIteratorMutableExplicitCbeginCend)
MLMODEL_TEST(testSpanTestsIteratorMutableExplicitRbeginRend)
MLMODEL_TEST(testSpanTestsMakeSpanArrayForcedImmutable)
MLMODEL_TEST(testSpanTestsMakeSpanArrayImmutable)
MLMODEL_TEST(testSpanTestsMakeSpanArrayMutable)
MLMODEL_TEST(testSpanTestsMakeSpanVectorForcedImmutable)
MLMODEL_TEST(testSpanTestsMakeSpanVectorForcedImmutableFromConst)
MLMODEL_TEST(testSpanTestsMakeSpanVectorImmutable)
MLMODEL_TEST(testSpanTestsMakeSpanVectorMutable)
MLMODEL_TEST(testSpanTestsSlicingBounded)
MLMODEL_TEST(testSpanTestsSlicingByDimension)
MLMODEL_TEST(testSpanTestsSlicingByDimensionWithInvalidIndex)
MLMODEL_TEST(testSpanTestsSlicingByInvalidDimension)
MLMODEL_TEST(testSpanTestsSlicingIllegalBounds)
MLMODEL_TEST(testSpanTestsSlicingUnbounded)
MLMODEL_TEST(testSpanTestsSlicingUnboundedEdge)
MLMODEL_TEST(testSpanTestsSlicingZeroLength)
MLMODEL_TEST(testSpanTestsSpanOverload)
MLMODEL_TEST(testSpanTestsStaticSizedAccessImmutable)
MLMODEL_TEST(testSpanTestsStaticSizedAccessMutable)
MLMODEL_TEST(testSpanTestsSubByteUIntValueAt)
MLMODEL_TEST(testSpanTestsSubbyteIntValueAt)
MLMODEL_TEST(testStorageIntegrationTestsReadDataWithIncorrectOffset)
MLMODEL_TEST(testStorageIntegrationTestsReadDataWithIncorrectType)
MLMODEL_TEST(testStorageIntegrationTestsWriteAndReadValues)
MLMODEL_TEST(testStorageReaderTestsAllOffsets)
MLMODEL_TEST(testStorageReaderTestsAllOffsetsWithEmptyBlobFile)
MLMODEL_TEST(testStorageReaderTestsBasicProperties)
MLMODEL_TEST(testStorageReaderTestsDataOffset)
MLMODEL_TEST(testStorageReaderTestsIncorrectDType)
MLMODEL_TEST(testStorageReaderTestsIncorrectMetadata)
MLMODEL_TEST(testStorageReaderTestsInt8Data)
MLMODEL_TEST(testStorageReaderTestsIsEncryptedWithEmptyBlobFile)
MLMODEL_TEST(testStorageReaderTestsRawData)
MLMODEL_TEST(testStorageReaderTestsThreeRecords)
MLMODEL_TEST(testStorageReaderTestsTruncatedData)
MLMODEL_TEST(testStorageReaderTestsTruncatedHeader)
MLMODEL_TEST(testStorageReaderTestsTruncatedMetadata)
MLMODEL_TEST(testStorageReaderTestsZeroRecords)
MLMODEL_TEST(testStorageWriterTestsAlignment)
MLMODEL_TEST(testStorageWriterTestsAppendToExistingFile)
MLMODEL_TEST(testStorageWriterTestsSupportedTypes)
// #end milblob

// Training input validation test

// All are non-classifier unless otherwise described. All include model inputs unless specified "Only"
MLMODEL_TEST(testInvalid_NoTrainingInputs)
MLMODEL_TEST(testInvalid_OnlyModelInputs)
MLMODEL_TEST(testInvalid_OnlyTarget)
MLMODEL_TEST(testInvalid_OnlyPredictedFeatureName)
MLMODEL_TEST(testInvalid_OnlyTargetAndPredictedFeatureName)
MLMODEL_TEST(testInvalid_TargetAndFakeModelInputs) // make a model with 1 input. Supply target and fake input not actually listed
MLMODEL_TEST(testInvalid_PredictedFeatureNameAndFakeModelInputs) // make a model with 1 input. Supply PFN and fake input not actually listed
MLMODEL_TEST(testInvalid_TargetPredictedFeatureNameAndFakeModelInputs) // make a model with 1 input. Supply target, PFN and fake input not actually listed
MLMODEL_TEST(testInvalid_PredictedFeatureName) // make a model with 1 input. Supply PFN and model input, should fail as not a classifier
MLMODEL_TEST(testValid_TargetAndPredictedFeatureName) // make a model w/ 1 input. Supply target, PFN, and this input, should pass
MLMODEL_TEST(testValid_TargetAndRealAndFakeTrainingInputs) // make a model w/ 1 input. Supply target, this input, and other fake input
MLMODEL_TEST(testValid_TargetOneOfTwoModelInputs) // make a model w/ 2 inputs. Supply target and 1 input
MLMODEL_TEST(testValid_TargetUnusedOneOfTwoModelInput) // make a model w/ 2 inputs only 1 is actually used. Supply the wrong one as TI
MLMODEL_TEST(testValid_1InferenceAnd3TrainingInputs) // // make a model w/ 1 input. Supply it and 3 training inputs (so they outnumber model inputs)
MLMODEL_TEST(testInvalid_Classifier_OnlyPredictedFeatureName)
MLMODEL_TEST(testInvalid_Classifier_OnlyTarget)
MLMODEL_TEST(testValid_Classifier_PredictedFeatureName)
MLMODEL_TEST(testValid_Classifier_Target)
MLMODEL_TEST(testValid_Classifier_PredictedFeatureNameAndTarget)
MLMODEL_TEST(testInvalid_Classifier_PredictedFeatureNameWrongType)
MLMODEL_TEST(testValid_WithMSE)
MLMODEL_TEST(testValid_Pipeline)

#undef MLMODEL_TEST
