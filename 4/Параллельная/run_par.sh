#!/bin/bash
#BSUB -J Array2DParallel
#BSUB -P Project
#BSUB -W 00:10
#BSUB -n 8
#BSUB -R "span[ptile=4]"
#BSUB -e error_par_2d.log
#BSUB -o output_par_2d.log

export OMP_NUM_THREADS=8
export ARRAY_SIZE=500
./par_2d