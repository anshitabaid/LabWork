set ns [new Simulator]
set nt [open simulate4.nam w]
$ns namtrace-all $nt

set tr [open simulate4.tr w]
$ns trace-all $tr

proc finish {} {
	global ns nt tr
	$ns flush-trace
	close $nt
	close $tr
	exec nam simulate4 &
	exit 0
}

set s [$ns node]
set r [$ns node]
set d [$ns node]

$ns duplex-link $s $r 1Mb 50ms DropTail
$ns duplex-link $r $d 100Kb 5ms DropTail
$ns duplex-link-op $s $r orient right
$ns duplex-link-op $r $d orient right

$ns queue-limit $r $d 10

set udp [new Agent/UDP]
$ns attach-agent $s $udp
set null [new Agent/Null]
$ns attach-agent $d $null
$ns connect $udp $null


set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 160kb
$cbr set random_ false





$ns at 0.1 "$cbr start"
$ns at 10 "finish"

$ns run