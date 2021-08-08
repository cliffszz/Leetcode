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

func (c *CQueue) AppendTail(value int) {
	c.stackIn.PushBack(value)
}

func (c *CQueue) DeleteHead() int {
	if c.stackOut.Len() == 0 {
		for c.stackIn.Len() > 0 {
			c.stackOut.PushBack(c.stackIn.Remove(c.stackIn.Back()))
		}
	}
	if c.stackOut.Len() != 0 {
		res := c.stackOut.Back()
		c.stackOut.Remove(res)
		return res.Value.(int)
	}
	return -1
}
