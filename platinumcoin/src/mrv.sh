#!/bin/bash


while :
do
	./platinumcoind -testnet sendtoaddress myoq946jrvuBCcHwzYV1cQV68Bdw1cVbjd "0.01000000ep" "$RANDOM"
	sleep 1
done
