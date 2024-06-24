class _DoubleLinkedBase:
	""" A base class providing a doubly linked list representation."""

	class _Node:
		""" Lightweight, nonpublic class for storing a doubly linked node"""
		__slots__ = '_element', '_prev', '_next' # streamline memory

		def __init__(self, element, prev, next): # initialize node's fields
			self._element = element
			self._prev = prev
			self._next = next

	def __init__(self):
		"""Create an empty list"""
		self._header = self._Node(None, None, None)
		self._trailer = self._Node(None, None, None)
		self._header._next = self._trailer
		self._trailer._prev = self._header
		self._size = 0 # number of elements

	def __len__(self):
		"""Return the number of elements in the list"""
		temp=self._header
		cnt=0
		while(temp != None):
			cnt=cnt+1
			temp=temp._next
		return cnt	

	def is_empty(self):
		"""Return true if list is empty"""
		if(self._header._element==None):
			return True
		else :
			return False

	def _insert_between(self, e, predecessor, successor):
		"""Add element e between two existing nodes and return new node"""
		newest = self._Node(e, predecessor, successor)
		temp=self._header
		while((temp!=None)and(temp._element!=predecessor)):
			temp=temp._next
		if(temp==None):
			print("given predecessor is not in the list")
			return
		temp1=temp._next
		temp._next=newest
		newest._next=temp1
		
		# ===== Start writing your code here =====
	     # Remove this statement once you write your code
		# ===== End writing your code here =====

	def _delete_node(self, node):
		"""Delete nonsentinel node from the list and return its elements"""
		temp=self._header
		temp1=self._header
	
		while((temp!=None)and(temp._element!=node)):
			temp1=temp
			temp=temp._next
			

		if(temp==None):
			print("given element is not in the list")
			return 
		temp1._next=temp._next
		#temp=None
		temp1._next._prev=temp1
		print(temp1._next._prev._element)
		
		

		# ===== Start writing your code here =====
		# Remove this statement once you write your code
		# ===== End writing your code here ===
# a=_DoubleLinkedBase()
# a._header._element=1
# a._trailer._element=4
# a._insert_between(2,1,4)
# a._insert_between(3,2,4)
# #._delete_node(2)
# a._delete_node(3)

# print(a.__len__())
# # print(a.is_empty())

