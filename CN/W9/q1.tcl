set ns [new Simulator]
$ns color 1 green
$ns color 2 Red
set nt [open q1.nam w]
$ns namtrace-all $nt

set tr [open q1.tr w]
$ns trace-all $tr

proc finish {} {
	global ns nt tr
	$ns flush-trace
	close $nt
	close $tr
	exec nam q1.nam &
	exit 0
}
set n0 [$ns node]
set n1 [$ns node]

$ns duplex-link $n0 $n1 10Mb 10ms DropTail

set udp [new Agent/UDP]
$ns attach-agent $n0 $udp

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 1mb
$cbr set random_ false

set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink
$ns connect $udp $sink
$tcp set fid_ 2