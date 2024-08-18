Have a binary you want to upload to a client Windows machine without generating network logs? This tool will help with that. 

Simply convert any binary to base64 with something like "base64 beacon.exe >> beacon.b64", then run bin2duck with the base64 file as a command line argument.

The resulting ducky script will output the base64 encoded binary to a temporary file, and then use "certutil" to decode it back to a binary on the client machine.
