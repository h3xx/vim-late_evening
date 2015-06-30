#!/usr/bin/perl -w
use strict;
our $VERSION = 0.06;

=pod
=item B<test>
=head2 fact($value...)
Finds the factorial of the value.
    example fact 6
=cut

sub fact($) {
	my @effs;
	# dying here
	die "no values: ${test}" . $This::Mod::lasterr . &getMsg()
		unless @_;
	foreach my $val (@_) {
		push @effs, 1;
		$effs[-1] *= $_
			for ($val < 0)
				? $val .. -1
				: 1 .. $val;
	}
	wantarray ? @effs : $effs[0]
}
