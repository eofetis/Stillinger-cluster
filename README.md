# Stillinger-cluster
A simple cluster analysis script for atomic systems

Given a vector of Atoms, generates a map 'atom index -> cluster size'. Clusters are defined based 
on the simple Stillinger criterion [Stillinger, F. H. J. Chem. Phys. 1963, 38, 1486–1494], 
using parameters
```
atype1, atype2, and rcut
```

The script can be easily modified to output, e.g., cluster size distribution etc. PBCs work for cubic boxes only
but can be easily extended.
