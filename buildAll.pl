#!/usr/bin/perl
use strict;
use Cwd;

`which qmake` or die "qmake is not in your path!\n";

my $srcDir=cwd();
my $buildDir="obsBuildAll";
my @qmakeTargets= ("configQtEmitter", "configBoostEmitter", "configTradEmitter");


chdir('..');
if (!-e $buildDir)  
{
	 print "Making directory\n";
	`mkdir $buildDir`;
}
chdir($buildDir);
foreach my $config (@qmakeTargets)
{
	my $exec="qmake $srcDir CONFIG+=$config";
	print "Executing $exec\n";
	`$exec`;
	`make`;
	`make clean`;
}
`rm Makefile`;
