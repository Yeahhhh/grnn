# grnn

comparing genome sequences using LSTM recurrent neural network



## encoding format
* format 1:          xxxxxx6yyyyyy1
* format 2:          xyxyxyxyxyxy1
* format 3:          xxxxxxyyyyyy1




## Observations
* The randomness of the data make significant differences. For fair comparison, the data set must be fixed.
( See format1_leng20_err0_500_100/*.png )

* Comparing the DNA sequence encoding format, format 2 > format 1 > format 3
( See formatMOD_leng20_err0_500_100/err*png )

* LSTM can classify the sequences, even if the match is not 100%
( See formatMOD_leng20_err0_500_100/err1*png )

* 2-neuron LSTM can deliver quite good performance on format 2 data.
However, the performance of 8-nerual LSTM is bad on format 1 data and format 3 data.
( See format1_leng20_err1_500_100__different_RNN/*.png )

* Using the full length data string in format 2, the 16-neural LSTM and 8-neuron LSTM gives good result.
( See formatMOD_leng65_err1_500_100/*.png )
