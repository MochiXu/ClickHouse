---
slug: /ru/sql-reference/aggregate-functions/reference/grouparraysample
sidebar_position: 114
---

# groupArraySample {#grouparraysample}

Создает массив из случайно выбранных значений аргумента. Количество элементов в массиве ограничено значением параметра `max_size`. Элементы добавляются в результирующий массив в случайном порядке.

**Синтаксис**

``` sql
groupArraySample(max_size[, seed])(x)
```

**Аргументы**

-   `max_size` — максимальное количество элементов в возвращаемом массиве. [UInt64](../../data-types/int-uint.md).
-   `seed` — состояние генератора случайных чисел. Необязательный параметр. [UInt64](../../data-types/int-uint.md). Значение по умолчанию: `123456`.
-   `x` — аргумент (название колонки таблицы или выражение).

**Возвращаемые значения**

-   Массив случайно выбранных значений аргумента `x`.

Тип: [Массив](../../data-types/array.md).

**Примеры**

Рассмотрим таблицу `colors`:

``` text
┌─id─┬─color──┐
│  1 │ red    │
│  2 │ blue   │
│  3 │ green  │
│  4 │ white  │
│  5 │ orange │
└────┴────────┘
```

Запрос с названием колонки таблицы в качестве аргумента:

``` sql
SELECT groupArraySample(3)(color) as newcolors FROM colors;
```

Результат:

```text
┌─newcolors──────────────────┐
│ ['white','blue','green']   │
└────────────────────────────┘
```

Запрос с названием колонки и другим состоянием генератора случайных чисел:

``` sql
SELECT groupArraySample(3, 987654321)(color) as newcolors FROM colors;
```

Результат:

```text
┌─newcolors─────────────────────────────┐
│ ['red','orange','green']              │
└───────────────────────────────────────┘
```

Запрос с выражением в качестве аргумента:

``` sql
SELECT groupArraySample(3)(concat('light-', color)) as newcolors FROM colors;
```
Результат:

```text
┌─newcolors───────────────────────────────────┐
│ ['light-blue','light-orange','light-green'] │
└─────────────────────────────────────────────┘
```
