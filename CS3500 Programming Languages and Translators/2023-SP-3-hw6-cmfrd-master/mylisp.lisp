;Programmer: Connor Marler
;Student ID: 12573275
;Section: 103
;Date: 05/12/23
;File: myLisp.cpp


(defun myLast (L)
  (cond 
    ((null L) nil) ; if L is empty, return nil
    ((null (cdr L)) (car L)) ; if L has only one element, return that element
    (t (myLast (cdr L))) ; otherwise, call myLast recursively with the rest of the list
  )    
)

(defun myCount(X L)
  (cond 
    ((null L) 0) ; if L is empty then there are no atom X in L
    ((eq X (car L)) (+ 1 (myCount X (cdr L)))) ; if X and the first element of L are the same then
                                               ; we increment the recursive call of the rest of the list by 1
    (t (myCount X (cdr L))) ; otherwise, call myCount recursively with the rest of the list
  )
)

(defun myMember (X  L)
  (cond 
    ((null L) nil) ; if L is empty then there are no atom X in L
    ((eq X (car L)) t) ; if X is the first element in L, then it is a memeber of L
    (t (myMember X (cdr L))) ; otherwise, call myMember recursively with the rest of the list
  )
)

(defun myPurge (L)
  (cond
    ((null L) nil) ; if L is empty then return nothing
    ((myMember (car L) (cdr L)) (myPurge (cdr L))) ; if the first element of L is in the rest of L
                                                   ; then recursively call myPurge with the rest of L
    (t (cons (car L) (myPurge (cdr L)))) ; otherwise, construct a new list with the first element of 
                                         ; L and another recursive call of myPurge
  )
)

(defun myCommon (L1 L2)
  (cond
    ((null L1) nil) ; if L1 is empty return nothing
    ((myMember (car L1) L2) (cons (car L1) (myCommon (cdr L1) L2))) ; if the first element of L1 is in L2
                                                                    ; then construct a list with the first element
                                                                    ; of L1 and the recursive call of myCommon with
                                                                    ; the rest of L1 and L2 
    (t (myCommon (cdr L1) L2)) ; otherwise, call myCommon recursively with rest of L1 and L2
  )
)

(defun myGen (X Y)
  (cond
    ((> X Y) nil) ; if X is greater than Y then return nothing
    (t (cons X (myGen (1+ X) Y))) ; otherwise, construct a new list with X as the  first element and with
                                  ; a recursive call with one more than X and Y
  )
)

(defun myMap (F L)
  (cond
    ((null L) nil) ; if L is empty then return nothing
    (t (cons (funcall F (car L)) (myMap F (cdr L)))) ; otherwise, construct a list with the application of F to the beginning
                                                     ; L and a recursive call with F and the rest of L
  )
)

(defun myReduce (F L)
  (cond 
    ((null (cdr L)) (car L)) ; if the rest of L is null then return the first element of L
    (t (funcall F (car L) (myReduce F (cdr L)))) ; otherwise, call the function F with the first element of L
                                                 ; and a recursive call with F and the rest of L
  )
)

