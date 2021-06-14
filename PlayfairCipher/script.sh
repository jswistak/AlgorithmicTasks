#!/bin/bash

KEY="KEY"
ALPHABET="ABCDEFGHIKLMNOPQRSTUVWXYZ"
MESSAGE="MESSAGE" # MESS TO END OR DEC 
ENC=1

#Read
#read -p "Enter key: " KEY
#read -p "Enter your message: " MESSAGE
#read -p "Enter 1 to encrypt or sth oter to decrypt: " ENC

#GETOTPS
while getopts "k:m:d" arg; do
  case $arg in
    k)
      KEY=$OPTARG
      #echo "Key: "$KEY
      ;; 
    m)
      MESSAGE=$OPTARG
      #echo "Message: "$message
      ;;
    d)
      ENC=0
      
      ;;
  esac
done

KEY=${KEY^^}
PREPROC=$KEY$ALPHABET
#Replace all J -> I
PREPROC=${PREPROC//J/I}
PREPROC=`echo $PREPROC | tr -d " \t\n\r" `
FINAL=""
declare -a OCURANCES

FINAL=`echo $PREPROC | tr -s 'A-Z'`
FINAL=`echo $PREPROC | awk -v FS="" '{ 
           for(i=1; i<=NF; i++) 
               if ($i==" " || !a[$i]++) printf "%s", $i; print "" 
       }'`
#echo $FINAL # KEY TO PASS TO FUNCTION 
#echo ${#FINAL}

declare -A matrix

#PRINT THE ENC/DEC MATRIX
for ((i=0;i<5;i++)) do
    for ((j=0;j<5;j++)) do
        ((ID=(i)*5+j))
        matrix[$i,$j]=${FINAL:$ID:1}

    done
done
echo "__ MATRIX __"
for ((i=0;i<5;i++)) do
    for ((j=0;j<5;j++)) do
        echo -n ${matrix[$i,$j]}

    done
    echo 
done
echo "___ END ___"

enc(){
    OUT_MESS=""
    for ((pos=0;pos<${#MESSAGE};pos+=2)) do
        X=${MESSAGE:$pos:1}
        Y=${MESSAGE:$pos+1:1}
        #AX=0
        #AY=0
        #BX=0
        #BY=0
        #echo $X
        #echo $Y
        for ((i=0;i<5;i++)) do
            for ((j=0;j<5;j++)) do
                if [ "$X" == "${matrix[$i,$j]}" ]; then
                    AX=$i
                    AY=$j
                fi
            done
        done
        for ((i=0;i<5;i++)) do
            for ((j=0;j<5;j++)) do
                if [ "$Y" == "${matrix[$i,$j]}" ]; then
                    BX=$i
                    BY=$j
                fi
            done
        done
        #TODO FUNC
        #echo
        #echo $AX
        #echo $AY
        #echo $BX
        #echo $BY
        #echo

        #SAME ROW
        if [ "$AX" -eq "$BX" ]; then 
            #echo "Same ROW"
            AY=$((($AY+1)%5))
            BY=$((($BY+1)%5))
            OUT_MESS=$OUT_MESS${matrix[$AX,$AY]}
            OUT_MESS=$OUT_MESS${matrix[$BX,$BY]}
        elif [ "$AY" -eq "$BY" ]; then 
            #echo "Same COLOMN"
            AX=$((($AX+1)%5))
            BX=$((($BX+1)%5))
            OUT_MESS=$OUT_MESS${matrix[$AX,$AY]}
            OUT_MESS=$OUT_MESS${matrix[$BX,$BY]}
        else
            #echo "DIFF"
            OUT_MESS=$OUT_MESS${matrix[$AX,$BY]}
            OUT_MESS=$OUT_MESS${matrix[$BX,$AY]}
            
        fi
        #SAME COLOMN 
        #DIFF
        
    done
    echo $OUT_MESS
}
dec(){
    OUT_MESS=""
    for ((pos=0;pos<${#MESSAGE};pos+=2)) do
        X=${MESSAGE:$pos:1}
        Y=${MESSAGE:$pos+1:1}
        #AX=0
        #AY=0
        #BX=0
        #BY=0
        #echo $X
        #echo $Y
        for ((i=0;i<5;i++)) do
            for ((j=0;j<5;j++)) do
                if [ "$X" == "${matrix[$i,$j]}" ]; then
                    AX=$i
                    AY=$j
                fi
            done
        done
        for ((i=0;i<5;i++)) do
            for ((j=0;j<5;j++)) do
                if [ "$Y" == "${matrix[$i,$j]}" ]; then
                    BX=$i
                    BY=$j
                fi
            done
        done
        #TODO FUNC
        #echo
        #echo $AX
        #echo $AY
        #echo $BX
        #echo $BY
        #echo

        #SAME ROW
        if [ "$AX" -eq "$BX" ]; then 
            #echo "Same ROW"
            AY=$((($AY+4)%5))
            BY=$((($BY+4)%5))
            OUT_MESS=$OUT_MESS${matrix[$AX,$AY]}
            OUT_MESS=$OUT_MESS${matrix[$BX,$BY]}
        elif [ "$AY" -eq "$BY" ]; then 
            #echo "Same COLOMN"
            AX=$((($AX+4)%5))
            BX=$((($BX+4)%5))
            OUT_MESS=$OUT_MESS${matrix[$AX,$AY]}
            OUT_MESS=$OUT_MESS${matrix[$BX,$BY]}
        else
            #echo "DIFF"
            
            
            OUT_MESS=$OUT_MESS${matrix[$AX,$BY]}
            OUT_MESS=$OUT_MESS${matrix[$BX,$AY]}
        fi
        #SAME COLOMN 
        #DIFF
        
    done
    echo $OUT_MESS
}

#read -p "Enter your message: " MESSAGE
#MESSAGE=`echo $MESSAGE | tr -s 'A-Z'`
MESSAGE=${MESSAGE^^}
MESSAGE=`echo $MESSAGE | tr -d " \t\n\r" `

X="X";
if [ $((${#MESSAGE}%2)) -eq 1 ] ; then
    echo ${#MESSAGE}
    echo $MESSAGE
    MESSAGE=$MESSAGE$X
fi

echo $MESSAGE

#read -p "Enter 1 to encrypt or sth oter to decrypt: " ENC

if [ $ENC = 1 ]; then
    echo "ENCRYPT"
    enc
else
    echo "DECRYPT"
    dec
fi

