---
slug: /zh/sql-reference/data-types/float
---
# Float32,Float64 {#float32-float64}

[浮点数](https://en.wikipedia.org/wiki/IEEE_754)。

类型与以下 C 语言中类型是相同的：

-   `Float32` - `float`
-   `Float64` - `double`

我们建议您尽可能以整数形式存储数据。例如，将固定精度的数字转换为整数值，例如货币数量或页面加载时间用毫秒为单位表示

## 使用浮点数 {#shi-yong-fu-dian-shu}

-   对浮点数进行计算可能引起四舍五入的误差。

<!-- -->

``` sql
SELECT 1 - 0.9
```

    ┌───────minus(1, 0.9)─┐
    │ 0.09999999999999998 │
    └─────────────────────┘

-   计算的结果取决于计算方法（计算机系统的处理器类型和体系结构）

-   浮点计算结果可能是诸如无穷大（`INF`）和«非数字»（`NaN`）。对浮点数计算的时候应该考虑到这点。

-   当一行行阅读浮点数的时候，浮点数的结果可能不是机器最近显示的数值。

## NaN和Inf {#data_type-float-nan-inf}

与标准SQL相比，ClickHouse 支持以下类别的浮点数：

-   `Inf` – 正无穷

<!-- -->

``` sql
SELECT 0.5 / 0
```

    ┌─divide(0.5, 0)─┐
    │            inf │
    └────────────────┘

-   `-Inf` – 负无穷

<!-- -->

``` sql
SELECT -0.5 / 0
```

    ┌─divide(-0.5, 0)─┐
    │            -inf │
    └─────────────────┘

-   `NaN` – 非数字

<!-- -->

    SELECT 0 / 0

    ┌─divide(0, 0)─┐
    │          nan │
    └──────────────┘

可以在 [ORDER BY 子句](../../sql-reference/data-types/float.md) 查看更多关于 `NaN` 排序的规则。
