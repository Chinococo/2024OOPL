# OOPL 雷電 base on Leistungsstarkes Game Framework

![image](https://github.com/Chinococo/2024OOPL/assets/58754099/42b6bae8-836e-4830-9dfe-f2043de8df97)

To-do list: https://github.com/users/Chinococo/projects/5


### 開發者原始資訊
LGF (Leistungsstarkes Game Framework) 是一款基於陳偉凱老師的 Game Framework 加上些許功能的 Powerful Game Framework。
專案不保證長期維護，有任何問題或者任何其他想要的 feature，請丟 issue，祝使用愉快 :D
base on https://github.com/ntut-xuan/LeistungsstarkesGameFramework


#### 使用手冊與函式庫

你可以在這裡找到這份專案的使用手冊與函式庫。

| 資源 | 連結 |
| ---- | ---- |
| 使用手冊 | https://lgf-readthedocs.readthedocs.io/zh_TW/latest/index.html |
| 函式庫 | https://ntut-xuan.github.io/LeistungsstarkesGameFramework |


#### 銘謝

謝謝 國立臺北科技大學 陳偉凱教授 開發了這個遊戲框架

並且謝謝 國立臺北科技大學 陳碩漢教授 同意這個框架能夠公開使用。


# 進度

期中：完成各角色之基礎邏輯與互動、圖片以及地圖配置。

期末：完成音效以及優化動畫，再視情況新增關卡。

1~3週：準備圖片／設計架構

4~6週：主選單／關卡架構實作／主要角色

7~9週：實作關卡1（地圖／敵人／子彈／道具）

10~12週：實作關卡1（Boss）

13~15週：實作關卡2（地圖／Boss）

16~18週：實作音效／實作動畫／實作關卡3（地圖／Boss）


# 命名規則

函式、類、列舉、命名空間：PascalCase

成員變數、區域變數、函式參數：snake_case

常數、列舉成員：ALL_UPPERCASE


# 注意事項
1. C++ 預設繼承類型為 private，請在繼承的時候特別註明 public，盡可能不要使用 private 繼承。
2. 函式定義、for、if 的上下請留空白行。函式宣告則不需要。
3. 請不要使用任何 using namespace。
4. 請盡可能使用 const reference。
5. 請盡可能不要重複程式碼。
6. 標頭檔副檔名固定 .h，原始檔附檔名固定 .cpp。

# 偵錯工具
&lt;data> 放想要顯示的資料。
```cpp
OutputDebugStringW(std::to_wstring( <data> ) + L"\n");
```
