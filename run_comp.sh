#!/bin/bash

DIR="entrada"
MODO=""
for ((j=0; j < 2; j+=1))
  do
    if [ $j -eq 0 ]
    then
      MODO="list"
    else
      MODO="heap"
    fi
    echo "N,Comparações" > saida_comp_$MODO.csv
    echo "Djiksta $MODO"
    for ((i = 10; i <= 1000; i*=10))
      do
        echo "Executando para $i vértices"
        echo -n "$i,"  >> saida_comp_$MODO.csv
        ./bin/graph.x $MODO "comp" < $DIR/Entrada\ $i.txt >> saida_comp_$MODO.csv
      done

    for ((i = 150; i <= 1500; i*=10))
      do
        echo "Executando para $i vértices"
        echo -n "$i,"  >> saida_comp_$MODO.csv
        ./bin/graph.x $MODO "comp" < $DIR/Entrada\ $i.txt >> saida_comp_$MODO.csv
      done

    for ((i = 25; i <= 250; i*=10))
      do
        echo "Executando para $i vértices"
        echo -n "$i,"  >> saida_comp_$MODO.csv
        ./bin/graph.x $MODO "comp" < $DIR/Entrada\ $i.txt >> saida_comp_$MODO.csv
      done

    for ((i = 200; i <= 500; i+=100))
      do
        echo "Executando para $i vértices"
        echo -n "$i,"  >> saida_comp_$MODO.csv
        ./bin/graph.x $MODO "comp" < $DIR/Entrada\ $i.txt >> saida_comp_$MODO.csv
      done

    i=75
    echo "Executando para $i vértices"
    echo -n "$i,"  >> saida_comp_$MODO.csv
    ./bin/graph.x $MODO "comp" < $DIR/Entrada\ $i.txt >> saida_comp_$MODO.csv

    i=50
    echo "Executando para $i vértices"
    echo -n "$i,"  >> saida_comp_$MODO.csv
    ./bin/graph.x $MODO "comp" < $DIR/Entrada\ $i.txt >> saida_comp_$MODO.csv

    i=650
    echo "Executando para $i vértices"
    echo -n "$i,"  >> saida_comp_$MODO.csv
    ./bin/graph.x $MODO "comp" < $DIR/Entrada\ $i.txt >> saida_comp_$MODO.csv

    i=800
    echo "Executando para $i vértices"
    echo -n "$i,"  >> saida_comp_$MODO.csv
    ./bin/graph.x $MODO "comp" < $DIR/Entrada\ $i.txt >> saida_comp_$MODO.csv
  done
