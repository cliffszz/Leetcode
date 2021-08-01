package offer

import (
	"container/list"
)

type CQueue struct {
	stackIn, stackOut *list.List
}

func Constructor() CQueue {
	return CQueue{
		stackIn:  list.New(),
		stackOut: list.New(),
	}
}

func (this *CQueue) AppendTail(value int) {
	this.stackIn.PushBack(value)
}

func (this *CQueue) DeleteHead() int {
	if this.stackOut.Len() == 0 {
		for this.stackIn.Len() > 0 {
			this.stackOut.PushBack(this.stackIn.Remove(this.stackIn.Back()))
		}
	}
	if this.stackOut.Len() != 0 {
		res := this.stackOut.Back()
		this.stackOut.Remove(res)
		return res.Value.(int)
	}
	return -1
}
