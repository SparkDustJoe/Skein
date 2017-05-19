# Skein Hash Algorithm
Skein (in Managed C++ .NET) v1.3 based on SHA3 Competition Submission to US NIST.
https://www.schneier.com/academic/skein/

Uses the Threefish encryption algorithm as a primitive in a chained block configuration to build a cryptographically sound hash function (see the original creator’s page for the white paper and related proofs).

This code base was developed over a number of years and originally lived in CodePlex before Microsoft decided to shutter the doors.  http://skeinlibmanaged.codeplex.com/ and http://skeinlib.codeplex.com/ LINKS FOR ARCHIVE PURPOSES ONLY!  There are some painful lessons in speed and security over the life of this code.

This uses Managed C++ for efficiency and a level of code reliability but is not necessarily optimized for maximum speed.  Having said that, when compiled as x64 Release mode, the throughput is adequately speedy for most applications.  The resulting DLL can be linked or MSIL merged into .NET code.

This code is Copyright © Dustin J. Sparks 2013-2017 but released into the Public Domain based on the original white paper and reference code from the Skein team. 

This is the live developed repository for this version.

# WARRANTY:  There is none, implied or expressed, for ANY purpose.  You use this code at your own risk!
This code contains cryptographic principles which may be restricted by US law for export and other local government laws regarding use and possession of such cryptography.  It is the responsibility of the user to determine legality of use and possession of such materials BEFORE downloading or utilizing the same.

This code is released into the public domain as an educational product and should be independently evaluated and audited before use in production or critical environments!  YOU’VE BEEN WARNED!

