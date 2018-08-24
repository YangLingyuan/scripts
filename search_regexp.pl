#!/vobs/cello/cade_struct/bin/perl
#
# search_regexp - Search for Perl regexp in set of files
#
# Usage :
#   search_regexp <file_set> '<regexp>'
#
# Parameters :
#   <file_set> : Text file containing the path + name of the targeted files. 
#                This file is most likely created using the 'find' command
#              
#   <regexp>   : perl regexp. Must be enclosed in '' 
# 
# Example 1: Find code matching perl regexp 'SETUP\w{0,}_REQ' under catalog xyz
#  >cd /repo/<user>/xyz
#  >find . -type f -name '*.h' -print > files.txt
#  >find . -type f -name '*.cc' -print >> files.txt
#  >search_regexp files.txt 'SETUP\w{0,}_REQ'
# 
# Example 2: Concatenate code files, with extension .cc and .h and .sig, to flat file
#  >cd /repo/<user>/xyz
#  >find . -type f -name '*.h' -print > files.txt
#  >find . -type f -name '*.cc' -print >> files.txt
#  >find . -type f -name '*.sig' -print >> files.txt
#  >search_regexp files.txt '.* >flat_code_file.txt
# 
use strict;

my %file_set;

# Read name of <file_set> file
my $file_set = shift @ARGV;

# Read <regexp>
my $regexp = shift @ARGV;

# Read option
my $option = shift @ARGV;

# Read <file_set> file
open (FILE_SET, '<', $file_set) || die "Could not find file_set \"$file_set\" \n";
while(defined(my $line = <FILE_SET>)) {
   if ($line =~ /^(.*)$/) {
      my $target_file = $1;
      open (TARGET, '<', $target_file) || die "Could not find target file \"$target_file\" \n";

      # Compare source line with <regexp>
      while(defined(my $target_line = <TARGET>)) {
         if ($target_line =~ /(.*$regexp.*)$/) {
            push @{ $file_set{$target_file} }, $1;
         }
      }
   }
}


# Sort target files
my @sorted_target = sort keys(%file_set);

# Print result
my $num = 0;
for my $target_file (@sorted_target) {
   $num++;
   print "\n################################################################################################# \n";
   printf "x###x $num)%-60s \n", $target_file;
   for my $found_string (@{ $file_set{$target_file} }) {
      printf "       %s\n", $found_string;
   }
}
if ($num eq 0) {
    printf "regexp \"$regexp\" not found in any file \n";
}




1;
