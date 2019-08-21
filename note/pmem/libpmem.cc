/*

  libpmem

==>>> pmem_is_pmem

  - determine if the given range is entirely  persistent memory. According to result, determine whether need pmem_persist / msync

==>>> pmem_map_file / pmem_unmap_file

  - based on mmap, but it also takes extra steps to make large page mappings more likely.
  - based on munmap

==>>> pmem_persist

  - program that needs to flush several discontiguous ranges can call pmem_flush for each range and then follow up by calling pmem_drain() once.
  - consist of two steps : 
    - pmem_flush
    - pmem_drain

==>>> pmem_msync

             int is_pmem = pmem_is_pmem(rangeaddr, rangelen);

               ... make changes to a range of pmem ... 

              if (is_pmem)
                  pmem_persist(subrangeaddr, subrangelen);
              else
                  pmem_msync(subrangeaddr, subrangelen);

*/

========================================================================================================


        int srcfd;
        char buf[BUF_LEN];
        char *pmemaddr;
        size_t mapped_len;
        int is_pmem;
        int cc;
      
        // open pmem file
        srcfd = open(argv[1], O_RDONLY);

        // map pmem file to virtual memory space
        pmemaddr = pmem_map_file(argv[2], BUF_LEN, PMEM_FILE_CREATE|PMEM_FILE_EXCL, 0666, &mapped_len, &is_pmem)

        // directly read
        read(srcfd, buf, BUF_LEN);

        if (is_pmem) {
          pmem_memcpy_persist(pmemaddr, buf, cc);
        } else {
          memcpy(pmemaddr, buf, cc);
          pmem_msync(pmemaddr, cc);
        }

        close(srcfd);
        pmem_unmap(pmemaddr, mapped_len);



