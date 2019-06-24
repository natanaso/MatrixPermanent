## Implementation of Exact (Nijenhuis and Wilf) and Approximate (Huber and Law) Permanent Algorithms
 + Authors: Nikolay Atanasov, Sean Bowman, Brian Butler

## Related Publications:

    @article{Atanasov_SemanticLocalization_IJRR15,
      author = {N. Atanasov and M. Zhu and K. Daniilidis and G. Pappas},
      title = {Localization from Semantic Observations via the Matrix Permanent},
      journal = {The International Journal of Robotics Research (IJRR)},
      year = {2015},
      volume = {35},
      pages = {73-99},
      doi = {http://www.dx.doi.org/10.1177/0278364915596589}
    }
    
    @inproceedings{Bowman_SemanticSLAM_ICRA17,
      author = {Sean Bowman and Nikolay Atanasov and Kostas Daniilidis and George Pappas},
      title = {Probabilistic Data Association for Semantic SLAM},
      booktitle = {IEEE Int. Conf. on Robotics and Automation (ICRA)},
      year = {2017},
      doi = {http://www.dx.doi.org/10.1109/ICRA.2017.7989203}
    }    
    
    
## Compilation:
 + c++:
 ```
 mkdir build && cd build && cmake .. && make && cd ..
 ```
 
 + matlab:
 ```
 mex src/permanentRNW_mex.cpp -outdir bin
 ```


