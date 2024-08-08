/*
# 카드 뭉치

<https://school.programmers.co.kr/learn/courses/30/lessons/159994>

---

# 문제 설명

코니는 영어 단어가 적힌 카드 뭉치 두 개를 선물로 받았습니다. 코니는 다음과 같은 규칙으로 카드에 적힌 단어들을 사용해 원하는 순서의 단어 배열을 만들 수 있는지 알고 싶습니다.

- 원하는 카드 뭉치에서 카드를 순서대로 한 장씩 사용합니다.
- 한 번 사용한 카드는 다시 사용할 수 없습니다.
- 카드를 사용하지 않고 다음 카드로 넘어갈 수 없습니다.
- 기존에 주어진 카드 뭉치의 단어 순서는 바꿀 수 없습니다.

예를 들어 첫 번째 카드 뭉치에 순서대로 ["i", "drink", "water"], 두 번째 카드 뭉치에 순서대로 ["want", "to"]가 적혀있을 때 ["i", "want", "to", "drink", "water"] 순서의 단어 배열을 만들려고 한다면 첫 번째 카드 뭉치에서 "i"를 사용한 후 두 번째 카드 뭉치에서 "want"와 "to"를 사용하고 첫 번째 카드뭉치에 "drink"와 "water"를 차례대로 사용하면 원하는 순서의 단어 배열을 만들 수 있습니다.
문자열로 이루어진 배열 `cards1`, `cards2`와 원하는 단어 배열 `goal`이 매개변수로 주어질 때, `cards1`과 `cards2`에 적힌 단어들로 `goal`를 만들 있다면 "Yes"를, 만들 수 없다면 "No"를 return하는 solution 함수를 완성해주세요.

---

# 제한사항

- 1 ≤ `cards1`의 길이, `cards2`의 길이 ≤ 10
    - 1 ≤ `cards1[i]`의 길이, `cards2[i]`의 길이 ≤ 10
    - `cards1`과 `cards2`에는 서로 다른 단어만 존재합니다.
- 2 ≤ `goal`의 길이 ≤ `cards1`의 길이 + `cards2`의 길이
    - 1 ≤ `goal[i]`의 길이 ≤ 10
    - `goal`의 원소는 `cards1`과 `cards2`의 원소들로만 이루어져 있습니다.
- `cards1`, `cards2`, `goal`의 문자열들은 모두 알파벳 소문자로만 이루어져 있습니다.

---

# 입출력 예

| cards1 | cards2 | goal | result |
| --- | --- | --- | --- |
| ["i", "drink", "water"] | ["want", "to"] | ["i", "want", "to", "drink", "water"] | "Yes" |
| ["i", "water", "drink"] | ["want", "to"] | ["i", "want", "to", "drink", "water"] | "No" |

---

# 입출력 예 설명

## 입출력 예 #1

본문과 같습니다.

## 입출력 예 #2

`cards1`에서 "i"를 사용하고 `cards2`에서 "want"와 "to"를 사용하여 "i want to"까지는 만들 수 있지만 "water"가 "drink"보다 먼저 사용되어야 하기 때문에 해당 문장을 완성시킬 수 없습니다. 따라서 "No"를 반환합니다.

*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    int idx1 = 0, idx2 = 0;
    for (string word : goal)
    {
        if (idx1 < cards1.size() && cards1[idx1] == word)
        {
            idx1++;
        }
        else if (idx2 < cards2.size() && cards2[idx2] == word)
        {
            idx2++;
        }
        else
        {
            return "No";
        }
    }
    return "Yes";
}

int main()
{
    vector<string> card1_1 = {"i", "drink", "water"};
    vector<string> card2_1 = {"want", "to"};
    vector<string> goal_1 = {"i", "want", "to", "drink", "water"};
    cout << solution(card1_1, card2_1, goal_1) << endl;

    vector<string> card1_2 = {"i", "water", "drink"};
    vector<string> card2_2 = {"want", "to"};
    vector<string> goal_2 = {"i", "want", "to", "drink", "water"};
    cout << solution(card1_2, card2_2, goal_2) << endl;
}
