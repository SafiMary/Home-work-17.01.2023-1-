#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <utility>

class DataManager {

public:
 int mostSearchedKey() {
 std::unordered_map<int, int> keyAmount; //создали мап
 for (size_t i = 0; i < _keys.size(); i++) { //прошли по вектору от 0 до конца
 const auto& [it, isInserted] = keyAmount.insert({_keys[i], 1 });//достаем из вектора ключ и значение
 if (!isInserted) {//если вставка не произошла, то
 int value = it->second;//достанем значение
 value++;//увеличиваем его
 keyAmount[_keys[i]] = value;//складываем обратно по адресу
 }
 }
 std::pair<int, int> key_biggestValue = {0,0};//переменная где храним самый большой элемент
 for (std::unordered_map<int, int>::const_iterator it = keyAmount.begin();it != keyAmount.end(); it++) {//проходим итератором от начала вектора до конца
 if (key_biggestValue.second < it->second) { 
 key_biggestValue = std::make_pair(it->first,it->second);//переопределяем пару
 }
 }
 return key_biggestValue.first;//возвращаем ключ значения которое повторялось больше всего
 }

private:
 std::vector<int> _keys = { 1,1,2,2,4,2,6,7,7,7,2 };
};



