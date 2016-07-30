```
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/generate-parentheses
@Language: Markdown
@Datetime: 16-07-17 12:20
```

http://www.cnblogs.com/theskulls/p/5349547.html

此类回溯问题关键是要判断：
1. 当前的局面是否可以加入最终结果？
2. 当前的局面是否合法？
3. 为当前局面的每一个下一步选择，并且迭代每一种下一个局面的情况。