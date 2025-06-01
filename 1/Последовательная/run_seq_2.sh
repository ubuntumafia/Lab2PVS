cat > run_seq_2.sh << 'EOF'
#!/bin/bash
#BSUB -J Seq_2
#BSUB -P MyProject
#BSUB -W 00:10          
#BSUB -n 2              
#BSUB -e error_seq_2.log
#BSUB -o output_seq_2.log

export ARRAY_SIZE=200000
./Task1_seq
EOF
