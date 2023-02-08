#ifndef RNN_DATA_H
#define RNN_DATA_H

#include "rnn.h"

#define INPUT_DENSE_SIZE 24
extern const DenseLayer input_dense;

#define VAD_GRU_SIZE 24
extern const GRULayer vad_gru;

#define NOISE_GRU_SIZE 48
extern const GRULayer noise_gru;

#define DENOISE_GRU_SIZE 96
extern const GRULayer denoise_gru;

#define DENOISE_OUTPUT_SIZE 22
extern const DenseLayer denoise_output;

#define VAD_OUTPUT_SIZE 1
extern const DenseLayer vad_output;

struct RNNState {
  float vad_gru_state[VAD_GRU_SIZE];
  float noise_gru_state[NOISE_GRU_SIZE];
  float denoise_gru_state[DENOISE_GRU_SIZE];
  void (*compute_gru_fct)(const GRULayer *gru, float *state, const float *input);
};


#endif
