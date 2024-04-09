#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <typename T>
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
		if (this->first == NULL) //스택이 비어있는지 확인
		{
			return false;
		}
		element = this-> first -> data;// element에 삭제할 값을 저장
		Node<T>*temp = this->first; //삭제될 노드를 가리키는 임시 포인터 temp 생성
		this->first= this ->first ->link; // first포인터를 2번째로 연결시켜 삭제할 노드의 연결을 끊어냄
		delete temp; //노드 삭제
		this->current_size--;  // 하나 삭제함을 사이즈에 반영
		return true;


			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
	}
};
