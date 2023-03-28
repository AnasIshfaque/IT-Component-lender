#ifndef UUID2380212826176
#define UUID2380212826176

/**
  * RandomForestClassifier(base_estimator=deprecated, bootstrap=True, ccp_alpha=0.0, class_name=RandomForestClassifier, class_weight=None, criterion=gini, estimator=DecisionTreeClassifier(), estimator_params=('criterion', 'max_depth', 'min_samples_split', 'min_samples_leaf', 'min_weight_fraction_leaf', 'max_features', 'max_leaf_nodes', 'min_impurity_decrease', 'random_state', 'ccp_alpha'), max_depth=10, max_features=sqrt, max_leaf_nodes=None, max_samples=None, min_impurity_decrease=0.0, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, n_estimators=10, n_jobs=None, num_outputs=4, oob_score=False, package_name=everywhereml.sklearn.ensemble, random_state=None, template_folder=everywhereml/sklearn/ensemble, verbose=0, warm_start=False)
 */
class RandomForestClassifier {
    public:

        /**
         * Predict class from features
         */
        int predict(float *x) {
            int predictedValue = 0;
            size_t startedAt = micros();

            
                    
            uint16_t votes[4] = { 0 };
            uint8_t classIdx = 0;
            float classScore = 0;

            
                tree0(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree1(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree2(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree3(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree4(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree5(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree6(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree7(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree8(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree9(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            

            // return argmax of votes
            uint8_t maxClassIdx = 0;
            float maxVote = votes[0];

            for (uint8_t i = 1; i < 4; i++) {
                if (votes[i] > maxVote) {
                    maxClassIdx = i;
                    maxVote = votes[i];
                }
            }

            predictedValue = maxClassIdx;

                    

            latency = micros() - startedAt;

            return (lastPrediction = predictedValue);
        }

        
            

            /**
             * Predict class label
             */
            String predictLabel(float *x) {
                return getLabelOf(predict(x));
            }

            /**
             * Get label of last prediction
             */
            String getLabel() {
                return getLabelOf(lastPrediction);
            }

            /**
             * Get label of given class
             */
            String getLabelOf(int8_t idx) {
                switch (idx) {
                    case -1:
                        return "ERROR";
                    
                        case 0:
                            return "LDR";
                    
                        case 1:
                            return "diode";
                    
                        case 2:
                            return "no_item";
                    
                        case 3:
                            return "transistor";
                    
                    default:
                        return "UNKNOWN";
                }
            }


            /**
             * Get latency in micros
             */
            uint32_t latencyInMicros() {
                return latency;
            }

            /**
             * Get latency in millis
             */
            uint16_t latencyInMillis() {
                return latency / 1000;
            }
            

    protected:
        float latency = 0;
        int lastPrediction = 0;

        
            

        
            
                /**
                 * Random forest's tree #0
                 */
                void tree0(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[9] <= 0.22453869506716728) {
                            
                                
                        if (x[49] <= 0.0029110033065080643) {
                            
                                
                        *classIdx = 0;
                        *classScore = 211.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[87] <= 0.13706058263778687) {
                            
                                
                        *classIdx = 3;
                        *classScore = 131.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 73.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 441.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #1
                 */
                void tree1(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[64] <= 0.3188864588737488) {
                            
                                
                        if (x[103] <= 0.20434576645493507) {
                            
                                
                        *classIdx = 2;
                        *classScore = 459.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[75] <= 0.15560000762343407) {
                            
                                
                        *classIdx = 3;
                        *classScore = 139.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 54.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 204.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #2
                 */
                void tree2(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[77] <= 0.001360174734145403) {
                            
                                
                        if (x[9] <= 0.13398893177509308) {
                            
                                
                        if (x[94] <= 0.2883267104625702) {
                            
                                
                        *classIdx = 0;
                        *classScore = 195.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 79.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 463.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[84] <= 0.10819406062364578) {
                            
                                
                        *classIdx = 0;
                        *classScore = 195.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[24] <= 0.6623393893241882) {
                            
                                
                        *classIdx = 1;
                        *classScore = 79.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 119.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #3
                 */
                void tree3(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[32] <= 0.13590163737535477) {
                            
                                
                        if (x[87] <= 0.22812379151582718) {
                            
                                
                        *classIdx = 2;
                        *classScore = 466.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 75.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[11] <= 0.4298578351736069) {
                            
                                
                        if (x[123] <= 0.48618699610233307) {
                            
                                
                        *classIdx = 3;
                        *classScore = 111.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[54] <= 0.2282970566302538) {
                            
                                
                        *classIdx = 1;
                        *classScore = 75.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 466.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 204.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #4
                 */
                void tree4(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[0] <= 0.39669710397720337) {
                            
                                
                        if (x[94] <= 0.021261686459183693) {
                            
                                
                        *classIdx = 0;
                        *classScore = 184.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[75] <= 0.14970315992832184) {
                            
                                
                        *classIdx = 3;
                        *classScore = 135.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 65.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 472.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #5
                 */
                void tree5(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[115] <= 0.0806708037853241) {
                            
                                
                        if (x[77] <= 0.002172060776501894) {
                            
                                
                        if (x[91] <= 0.013037770055234432) {
                            
                                
                        *classIdx = 1;
                        *classScore = 50.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 485.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[130] <= 0.09166252613067627) {
                            
                                
                        *classIdx = 3;
                        *classScore = 123.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 50.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 198.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #6
                 */
                void tree6(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[80] <= 0.9995085299015045) {
                            
                                
                        if (x[50] <= 0.0006877222913317382) {
                            
                                
                        if (x[108] <= 0.11273302882909775) {
                            
                                
                        if (x[79] <= 0.668024018406868) {
                            
                                
                        *classIdx = 3;
                        *classScore = 128.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 463.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 197.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[78] <= 0.21181023865938187) {
                            
                                
                        *classIdx = 3;
                        *classScore = 128.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 68.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[67] <= 0.3540499210357666) {
                            
                                
                        *classIdx = 2;
                        *classScore = 463.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 3;
                        *classScore = 128.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #7
                 */
                void tree7(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[90] <= 0.29811737686395645) {
                            
                                
                        if (x[68] <= 0.2833733558654785) {
                            
                                
                        *classIdx = 2;
                        *classScore = 437.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[75] <= 0.14970315992832184) {
                            
                                
                        *classIdx = 3;
                        *classScore = 129.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 74.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 216.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #8
                 */
                void tree8(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[12] <= 0.08418392017483711) {
                            
                                
                        if (x[132] <= 0.008848944678902626) {
                            
                                
                        *classIdx = 0;
                        *classScore = 221.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 449.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[99] <= 0.25038531608879566) {
                            
                                
                        if (x[91] <= 0.0041572535410523415) {
                            
                                
                        *classIdx = 1;
                        *classScore = 80.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[1] <= 0.7268171012401581) {
                            
                                
                        *classIdx = 3;
                        *classScore = 106.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 449.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 221.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #9
                 */
                void tree9(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[62] <= 0.10972784087061882) {
                            
                                
                        if (x[88] <= 0.615004226565361) {
                            
                                
                        if (x[93] <= 0.28973841667175293) {
                            
                                
                        *classIdx = 3;
                        *classScore = 140.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 72.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 2;
                        *classScore = 435.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 209.0;
                        return;

                            
                        }

                }
            
        


            
};



static RandomForestClassifier classifier;


#endif