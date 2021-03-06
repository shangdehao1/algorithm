
/*
 * Layout 
 * 
 *    libpmemobj defines a set of macros for convenient declaration of a pool's layout.  
 *    The layout declaration consists of declarations of a number of used types. 
 *    The declared types will be assigned consecutive type numbers.
 * 
 *          POBJ_LAYOUT_BEGIN(layout)
 *          POBJ_LAYOUT_TOID(layout, TYPE)
 *          POBJ_LAYOUT_ROOT(layout, ROOT_TYPE)
 *          POBJ_LAYOUT_END(layout)
 *
 *
 *          POBJ_LAYOUT_NAME(layout)
 *          POBJ_LAYOUT_TYPES_NUM(layout)
 * 
 *        EXAMPLE
 * 
 *           This is an example of layout declaration:
 */

                 POBJ_LAYOUT_BEGIN(mylayout);
                 POBJ_LAYOUT_ROOT(mylayout, struct root);
                 POBJ_LAYOUT_TOID(mylayout, struct node);
                 POBJ_LAYOUT_TOID(mylayout, struct foo);
                 POBJ_LAYOUT_END(mylayout);

                 struct root
                 {
                     TOID(struct node) node;
                 };

                 struct node
                 {
                     TOID(struct node) next;
                     TOID(struct foo) foo;
                 };

//          The name of layout and the number of declared types can be retrieved using the following code:

                 const char *layout_name = POBJ_LAYOUT_NAME(mylayout);
                 int num_of_types = POBJ_LAYOUT_TYPES_NUM(mylayout);


// ================================================

ROOT

The root object of a persistent memory pool is an entry point for all other persistent objects allocated using the libpmemobj API. 
In other words, every object stored in the persistent memory pool has the root object at the end of its reference path.  
It may be assumed that for each persistent memory pool the root object always exists, and there is exactly one root object in each pool.

pmemobj_root  

POBJ_ROOT : 
  - POBJ_ROOT() returns a typed OID of type TYPE instead of the PMEMoid returned by pmemobj_root().


pmemobj_create / pmemobj_open / pmemobj_close / pmemobj_check

  - Once created or opened, the memory pool is represented by an opaque handle, of type PMEMobjpool*, which is passed to most of the other libpmemobj functions.
  

pmemobj_persist

  - consist of pmemobj_flush and pmemobj_drain

pmemobj_memmove, pmemobj_memcpy, pmemobj_memset ---> pmemobj_memcpy_persist, pmemobj_memset_persist

  - firstly memmove, memcpy and memset, then flush them.


pmemobj synchronization primitives

  - pmemobj_mutex_zero / pmemobj_mutex_lock / pmemobj_mutex_timedlock /  pmemobj_mutex_trylock / pmemobj_mutex_unlock

  - pmemobj_rwlock_zero / pmemobj_rwlock_rdlock / pmemobj_rwlock_wrlock / pmemobj_rwlock_timedrdlock / pmemobj_rwlock_timedwrlock / pmemobj_rwlock_tryrdlock / pmemobj_rwlock_trywrlock / pmemobj_rwlock_unlock 

  - pmemobj_cond_zero / pmemobj_cond_broadcast / pmemobj_cond_signal / pmemobj_cond_timedwait / pmemobj_cond_wait pmemobj synchronization primitives



pmemobj type safety mechansim

  - TOID(TYPE)
        The TOID() macro declares a handle to an object of type TYPE, where TYPE is the name of a user-defined structure.  
        The typed OID must be declared first using the TOID_DECLARE(), TOID_DECLARE_ROOT(), POBJ_LAYOUT_TOID(3) or POBJ_LAYOUT_ROOT(3) macros.




Transaction

       The  non-transactional functions and macros described in pmemobj_alloc, pmemobj_list_insert and POBJ_LIST_HEAD only guarantee the atomicity of a single operation on an object.  In case of more complex changes involving
       multiple operations on an object, or allocation and modification of multiple objects, data consistency and fail-safety may be provided only by using atomic transactions.

       A transaction is defined as series of operations on persistent memory objects that either all occur, or nothing occurs.  In particular, if the execution of a transaction is interrupted by  a  power  failure  or  a  system
       crash,  it is guaranteed that after system restart, all the changes made as a part of the uncompleted transaction will be rolled back, restoring the consistent state of the memory pool from the moment when the transaction
       was started.

       Note that transactions do not provide atomicity with respect to other threads.  All the modifications performed within the transactions are immediately visible to other threads.  Therefore it is the responsibility of  the
       application to implement a proper thread synchronization mechanism.

       Each  thread  may have only one transaction open at a time, but that transaction may be nested.  Nested transactions are flattened.  Committing the nested transaction does not commit the outer transaction; however, errors
       in the nested transaction are propagated up to the outermost level, resulting in the interruption of the entire transaction.

       Each transaction is visible only for the thread that started it.  No other threads can add operations, commit or abort the transaction initiated by another thread.  Multiple threads may have transactions open on  a  given
       memory pool at the same time.



              TX_BEGIN(Pop) 
              {
                  /* the actual transaction code goes here... */
              } 
              TX_ONCOMMIT 
              {
                  /*
                   * optional - executed only if the above block
                   * successfully completes
                   */
              }
              TX_ONABORT 
              {
                  /*
                   * optional - executed only if starting the transaction fails,
                   * or if transaction is aborted by an error or a call to
                   * pmemobj_tx_abort()
                   */
              } 
              TX_FINALLY 
              {
                  /*
                   * optional - if exists, it is executed after
                   * TX_ONCOMMIT or TX_ONABORT block
                   */
              } 
              TX_END


// =====================================================

alloc persistent memory

   Functions described in this document provide the mechanism to allocate, resize and free objects from the persistent memory pool in a thread-safe and fail-safe manner.  
   All the routines are atomic  with  respect  to  other threads  and  any power-fail interruptions.  
   If any of these operations is torn by program failure or system crash, on recovery they are guaranteed to be entirely completed or discarded, leaving the persistent memory heap
   and internal object containers in a consistent state.

   All these functions can be used outside transactions.  Note that operations performed using the non-transactional API are considered durable after completion, even if executed within an open transaction.  Such  non-trans‐
   actional changes will not be rolled back if the transaction is aborted or interrupted.


              typedef int (*pmemobj_constr)(**PMEMobjpool *pop, void *ptr, void *arg);
              int pmemobj_alloc(PMEMobjpool *pop, PMEMoid *oidp, size_t size, uint64_t type_num, pmemobj_constr constructor, void *arg);
              int pmemobj_xalloc(PMEMobjpool *pop, PMEMoid *oidp, size_t size, uint64_t type_num, uint64_t flags, pmemobj_constr constructor, void *arg); (EXPERIMENTAL)
              int pmemobj_zalloc(PMEMobjpool *pop, PMEMoid *oidp, size_t size, uint64_t type_num);
              void pmemobj_free(PMEMoid *oidp);

              int pmemobj_realloc(PMEMobjpool *pop, PMEMoid *oidp, size_t size, uint64_t type_num);
              int pmemobj_zrealloc(PMEMobjpool *pop, PMEMoid *oidp, size_t size, uint64_t type_num);
              int pmemobj_strdup(PMEMobjpool *pop, PMEMoid *oidp, const char *s, uint64_t type_num);
              int pmemobj_wcsdup(PMEMobjpool *pop, PMEMoid *oidp, const wchar_t *s, uint64_t type_num);
              size_t pmemobj_alloc_usable_size(PMEMoid oid);

              POBJ_NEW(PMEMobjpool *pop, TOID *oidp, TYPE, pmemobj_constr constructor, void *arg)
              POBJ_ALLOC(PMEMobjpool *pop, TOID *oidp, TYPE, size_t size, pmemobj_constr constructor, void *arg)
              POBJ_ZNEW(PMEMobjpool *pop, TOID *oidp, TYPE)
              POBJ_ZALLOC(PMEMobjpool *pop, TOID *oidp, TYPE, size_t size)
              POBJ_REALLOC(PMEMobjpool *pop, TOID *oidp, TYPE, size_t size)
              POBJ_ZREALLOC(PMEMobjpool *pop, TOID *oidp, TYPE, size_t size)
              POBJ_FREE(TOID *oidp)



reverse persistent memory

   All of the functions described so far have an immediate effect on the persistent state of the pool, and as such, the cost of maintaining fail-safety is paid outright and, most importantly, in the calling thread.  This be‐
   havior makes implementing algorithms involving relaxed consistency guarantees difficult, if not outright impossible.

   The following set of functions introduce a mechanism that allows one to delay the persistent publication of a set of prepared actions to an arbitrary moment in time of the execution of a program.

   The  publication  is fail-safe atomic in the scope of the entire collection of actions.  If a program exits without publishing the actions, or the actions are canceled, any resources reserved by those actions are released
   and placed back in the pool.

   A single action is represented by a single struct pobj_action.  Functions that create actions take that structure by pointer, whereas functions that publish actions take array of actions and the size of  the  array.   The
   actions  can  be created, and published, from different threads.  When creating actions, the act argument must be non-NULL and point to a struct pobj_action, the structure will be populated by the function and must not be
   modified or deallocated until after publishing.


              PMEMoid pmemobj_reserve(PMEMobjpool *pop, struct pobj_action *act, size_t size, uint64_t type_num); (EXPERIMENTAL)
              PMEMoid pmemobj_xreserve(PMEMobjpool *pop, struct pobj_action *act, size_t size, uint64_t type_num, uint64_t flags); (EXPERIMENTAL)

              void pmemobj_defer_free(PMEMobjpool *pop, PMEMoid oid, struct pobj_action *act);
              void pmemobj_set_value(PMEMobjpool *pop, struct pobj_action *act, uint64_t *ptr, uint64_t value); (EXPERIMENTAL)

              int pmemobj_publish(PMEMobjpool *pop, struct pobj_action *actv, size_t actvcnt); (EXPERIMENTAL)
              int pmemobj_tx_publish(struct pobj_action *actv, size_t actvcnt); (EXPERIMENTAL)

              pmemobj_cancel(PMEMobjpool *pop, struct pobj_action *actv, size_t actvcnt); (EXPERIMENTAL)

              POBJ_RESERVE_NEW(pop, t, act) (EXPERIMENTAL)
              POBJ_RESERVE_ALLOC(pop, t, size, act) (EXPERIMENTAL)
              POBJ_XRESERVE_NEW(pop, t, act, flags) (EXPERIMENTAL)
              POBJ_XRESERVE_ALLOC(pop, t, size, act, flags) (EXPERIMENTAL)













