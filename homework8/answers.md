# Answers to the questions

1. The main difference between the 'struct' and 'class' is their accesibility. 'Struct' is public by default and 'class' is private by default. Meaning, code outside 'struct' can read and change it, while only code inside a 'class' can read and change it.

2. I have renamed it as myclass (I know very original, but physicists are not imaginative with names)

3. We derive our class from TObject in order to integrate it with ROOT and in order to get all the ROOT features such as IO streming, RTTI and the ROOT managment system. We can also store objects in ROOT containers such as TTree.

4. Yet to be seen
