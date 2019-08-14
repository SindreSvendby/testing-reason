## Example repo 

# Bug? 

This branch do not give proper error message, it only fails with status code 2. 

1. Is there something wrong with the code? Could be...

2. If so, why should not bsb give me any information about it?

[](bsb-not-working-powershell.PNG)

`bsb -clean-world` + `bsb -make-world` did not help. 

Tried in both wsl and powershell, with bs-platform as local and as global dependencies. 
Also tried to remove yarn.lock + remove node_moduels + yarn.
 

## Working branch
See branch `working-example` for an almost identicly branch that works. 