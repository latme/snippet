#!/usr/bin/env bash


# on server
# ---------
# -s, --server  running as server
# -D, --daemon  running on backend
# -p, --port n  specific listen port
iperf3 -s -D -p 9901
iperf3 -s -D -p 9902
iperf3 -s -D -p 8801
iperf3 -s -D -p 8802


# on client
# ---------
# -c, --client host  running as client, and specifing the server ip to connect.
# -p, --port n       specifing the server port to connect
# -t, --time n       running times by second, max value is 86400 (i.e. 24 hours), default is 10.
# -R, --reverse      reserse test data flow direction. this result in test data sent by server.
# -i, --interval n   peroid of print by second, default is 1. no print if 0.
#
# -b, --bandwidth n[KM]  Set target bandwidth to n bits/sec (default 1 Mbit/sec for UDP, unlimited for TCP).
# -w, --window n[KM]     Sets the socket buffer sizes to the specified value.
#                        For TCP, this sets the TCP window size.
iperf3 -c 192.168.101.7 -p 9901 -t 86400 -i 0 &
iperf3 -c 192.168.102.7 -p 9902 -t 86400 -i 0 &
iperf3 -c 192.168.101.7 -p 8801 -t 86400 -i 0 -R &
iperf3 -c 192.168.102.7 -p 8802 -t 86400 -i 0 -R &




