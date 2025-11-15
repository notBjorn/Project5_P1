---
date made: 2025-11-14
time made: 12:13
year: 2025
tags:  
- CS315
- Fall2025
aliases: ## Alternative terms for the doc
description: "Readme for the project 5 part 1"

## Categorizations.
isWork: true
isPersonal: false
isCasual: false
isLearn: true
isMisc: false
isJournal: false
isCoursework: true
---
> by Rishav Sharma,  SSU ID **007747214**
> [Github Repo](https://github.com/notBjorn/Project5_P1)

## **Collaboration & Sources**
Showed my output for trace files to my peers to ask if they could find any error. I did use AI but not for help with the code but mainly in finding where I wanted to go as the directory was so big and when I first started the project I had issues finding the code that I wanted to modify and understand . For example I wanted to see how find min was working but wasn't sure where the `findMin` was so I asked the GPT about it and found it in the harness.

## **Implementation Details**
### Trace Generator
- Created a `batch_then_drain` directory and added a main file in it
- Then added the following code to `cmake` to create a new profile to run

```cmake
  add_executable(batch_then_trace  
        src/trace-generators/batch_then_drain/main.cpp)  
```
- copied over the code from Huffman Trace code to the new file.
- modified the string with the new filename in the `traceConfig config` now `traceCofig` should generate appropriate output.
- Commented out the code for `choose_key_upper_bound` as that is not needed in our case
- changed `key_max` to be just `n` in trace loop
  - after sharing my trace files to confirm what i had was correct, Will pointed out that my insert values were really small. I realized that my output was scaling with `N`  and the instructions say to have the max be `2^20` I modified that and now it works better.
- changed the output for `extract_min` as we are only extracting min and not using the `E E I` behavior that is required in the Huffman tree.
- Had to edit the configuration of the working directory to be the directory that is supposed to contain, batch then drain traces.
- `C:/Users/Bhalu Da PC/CLionProjects/Project5_P1/src/trace-generators/batch_then_drain`
- The traces were generated successfully
```trace
batch_then_drain 13 23  
I     542427         0  
I     701600         1  
I     992963         2  
I     193975         3  
I     802643         4  
I     819651         5  
I     296114         6  
I     601787         7  
I     231783         8  
I     463381         9  
I     719557        10  
I     192933        11  
I     175259        12  
E  
E  
E  
E  
E  
E  
E  
E  
E  
E  
E  
E  
E
```


### Harness
- Created a new directory called `harness_fBTD` meaning *harness for batch then drain*.
- Copied over the all the harness files into this directory and then modified the `Cmake` file to have another profile that included these files. Just copied the code from the Huffman profile `add_executable` and modified the directory name and kept everything else the same.
- Modified the input trace files in the Harness to the batch-then-drain trace
- Changed the upper limit for quadratic oracle to be 2^15 and not 16 as that was causing the graph to look bad. This was pointed out by Will after I showed him my graph.
- Wrote code that generates the `.csv` files.
  ![the output graph](images/img.png)
## **Testing & Status**
***The code to my knowledge is working perfectly***
### What i did to run my code
- Created two different configurations in clion
  - One for the trace generator called `batch_then_trace` with the working directory `C:/Users/Bhalu Da PC/CLionProjects/Project5_P1/src/trace-generators/batch_then_drain`
  - The second config was for the new harness called `harness_fBTD` with the working directory `C:/Users/Bhalu Da PC/CLionProjects/Project5_P1/traces/batch_then_drain`
- First generate the trace by running config `batch_then_trace`, this will create the trace files that the harness will use to time the operations. To use the harness switch over to `harness_fBTD` config and run it this should generate the `csv` output that can be used in html graph. In the html graph select `browse` to import the desired csv file.
- The csv file is being generated in the `csvs` directory.
