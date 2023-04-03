print "Enter a string: ";
my $string = <STDIN>;
chomp($string);
my $rev = reverse($string);

if($rev eq $string){
    print "The string is a palindrome!\n";
} else {
    print "The string is not a palindrome.\n";
}