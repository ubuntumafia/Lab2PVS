cat > run_par_2.sh << 'EOF'
#!/bin/bash
#BSUB -J Par_2
#BSUB -P MyProject
#BSUB -W 00:10
#BSUB -n 2
#BSUB -e error_par_2.log
#BSUB -o output_par_2.log

export OMP_NUM_THREADS=2
export ARRAY_SIZE=200000
./Task1_par
EOF
