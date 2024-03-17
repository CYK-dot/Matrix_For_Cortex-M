Matrix_For_Cortex-M
=======================================
# introduction 介绍
本仓库fork自Amoiensis的Matrix_Hub,分离.c与.h，便于移植到单片机平台上。改动如下:
- 原Matrix.h中的malloc,free,printf,system改为OS_Malloc,OS_Free,OS_Err_Collector,OS_Commander
- 以上提到的函数存放于Matrix_OS_Config.c中，可以根据不同的硬件平台编写对应的适配函数。
- 更名state.h为Matrix_Config.h,并拆分出Matrix_OS_Config.c
- 将matrix.h拆分为Matrix_Hub.c与matrix.h

---------------------------------------
# 原作者信息
A lib for Matrix Operations in C language. (矩阵运算库--C语言) 

Author: Amoiensis (Xiping.Yu)

Email: Amoiensis@outlook.com

Data: 2020.02.12~2023.08.21

---------------------------------------
# 操作
|                     操作                      |    Func Name     |                     Operation (detailed)                     |
| :-------------------------------------------: | :--------------: | :----------------------------------------------------------: |
|                   生成矩阵                    |    Matrix_gen    |                   Generate  a new Matrix.                    |
|                   复制矩阵                    |   Matrix_copy    |                    Copy  to a new Matrix.                    |
|                   释放内存                    |      M_free      |           Free  the memory of the Matrix (create).           |
|                   矩阵显示                    |     M_print      |                       Print,  Display.                       |
|                单位矩阵(生成)                 |       M_I        |            Generate  a identity Matrix (create).             |
|                生成(全)零矩阵                 |     M_Zeros      |            Generation  All-Zeros-Matrix (create).            |
|                生成(全)一矩阵                 |      M_Ones      |            Generation  All-Ones-Matrix (create).             |
|               生成希尔伯特矩阵                |     Hilbert      |              Generate  Hilbert Matrix (create).              |
|                    加减法                     |    M_add_sub     |               Addition/  subtraction (create).               |
|                     乘法                      |      M_mul       |    Matrix  multiplication (create new one, abbr. create).    |
|                   矩阵数乘                    |     M_numul      |               Number  Multiplication (create).               |
|         矩阵对应元素乘/除 (哈达玛积)          |    M_pmuldiv     | Hadamard  Product : Multiply / Divide every element in the two Matrix-s (create). |
|          矩阵对矩阵，对各行进行数乘           |    M_numul_m     |    Matrix  Number Multiplication (using matrix transfer)     |
|                     求逆                      |    M_Inverse     |                      Inverse  (create).                      |
|                     伪逆                      |    M_pinv     |          left and right inverses / pseudo-inverse of Matrix.  (create).                      |
|                     转置                      |       M_T        |                     Transpose  (create).                     |
|                    行列式                     |      M_det       |                         Determinant.                         |
|                      迹                       |       M_tr       |                            Trace.                            |
|                     范数                      |      M_norm      |                  Norm  (1/ 2/ p/ INF/ FRO).                  |
|                   矩阵求秩                    |      M_rank      |                            Rank.                             |
|                 矩阵求条件数                  |      M_cond      |                Conditon  Value of the Matrix.                |
|           矩阵最大特征值、特征向量            |   M_eigen_max    | The maximum eigenvalue/ eigen-vector of the Matrix (create). |
|                  矩阵特征值                   |   M_eigen_val    |           The eigenvalues of the Matrix (create).            |
|      矩阵特征值, 及其对应特征向量(矩阵)       |     M_eigen      |  The eigenvalues and eigen-vectors of the Matrix (create).   |
|                  矩阵绝对值                   |      M_abs       |   Absolute  the value of elements in the Matrix  (create).   |
|                矩阵行(列)调换                 |      M_Swap      |              Swap  row or cloumn of the Matrix.              |
|                 矩阵基本变换                  |    M_E_trans     |              Matrix  elementary transformation.              |
|                 基本变换矩阵                  | Etrans_2_Matrix  | Transforms  the elementary transformation into Matrix (create). |
|             基本变换矩阵的逆矩阵              | Etrans_4_Inverse |   Inverse  Matrix of elementary transformations (create).    |
|                   上三角化                    |     M_Uptri_     | Upper-Triangulation  transformation on the Matrix (create).  |
|                   下三角化                    |    M_Lowtri_     | Lower-Triangulation  transformation on the Matrix (create).  |
|                    对角化                     |    M_Diatri_     |                  Diagonalization  (create).                  |
|                 对角矩阵求逆                  |    M_Dia_Inv     |        The  inverse of the diagonal Matrix (create).         |
|               上三角化(求逆用)                |   M_Uptri_4inv   | For  inverse, upper-triangulation transformation on the Matrix (create). |
|               下三角化(求逆用)                |  M_Lowtri_4inv   | For  inverse , lower-triangulation transformation on the Matrix (create). |
|      向量householder变换, 返回变换矩阵H       |   householder    | Householder transformation for  the Vector, return Transformating-Matrix: H (create). |
|              矩阵householder变换              |  M_householder   | Householder transformation for  the Matrix, return Transformated-Matrix: H_Mat (create). |
|                  矩阵QR分解                   |       M_QR       |                  QR Decomposition (create).                  |
|                  矩阵SVD分解                   |       M_SVD       |                  SVD Decomposition. (create).                  |
|                 切取部分矩阵                  |      M_Cut       |       Cut out a part-matrix from the Matrix (create).        |
|           从矩阵中抽取/采样特定的行/列.           |      M_Sample       |       Sample some row/col from Matrix. (create).        |
|                     填充                      |      M_full      |             Full  the Matrix with data (create).             |
|              (使用矩阵)填充矩阵               |    M_matFull     |            Full  the Matrix with another Matrix.             |
|            矩阵按列求和/向量元素和            |      M_sum       | Matrix  Column-Summation (create). / Vector element Sum (create) . |
|          寻找矩阵对应值位置(列优先)           |      M_find      | Find  all the positions with a certain value in the Matrix (create). |
|   矩阵按列最小行位置     /向量最小元素位置    |      M_min       | Minimum-value position for each row in  the Matrix (create) .  / Vector minimum element position (create) . |
|   矩阵按列最大行位置     /向量最大元素位置    |      M_max       | Maximum-value position for each row in  the Matrix (create)./ Vector Maximum element position (create) . |
|            矩阵各列指定行位置的值             |   M_minax_val    | The value of those given (row) positions for each column in the matrix (create). |
| 矩阵各位置与给定值比较     (返回矩阵,取值0/1) |  M_logic_equal   | Compare every element /pisition of the  Matrix with certain value (create).     [ More : Return a new Matrix, whose every value is 0/1. ] |
|            两矩阵对应位置逻辑运算             |     M_logic      | Logical  operation of corresponding positions of two matrices |
|          矩阵批量赋值(使用矩阵传递)           |     M_setval     |       Setting  Values of a Matrix with another Matrix.       |
|      (函数: M_rank) 释放初等变换内存空间      |   Etrans_free    | (In  Func: M_rank) Free memory for Elementary Transformation. |
|                     帮助                      |       help       |                            Help.                             |


ATTENTION
---------------------------------------

Please feel free to contact with me for any questions, thank you!

Don't spread the files without permission!

所有文件仅仅供学习交流！

***************************************
