#pragma once

#include "utils.hpp"

namespace ft
{
	template <typename T>
	class vector_iterator
	{
	public:
		typedef T value_type;
		typedef std::random_access_iterator_tag iterator_category;
		typedef std::ptrdiff_t difference_type;
		typedef value_type *pointer;
		typedef value_type &reference;

	protected:
		value_type *_p;

	public:
		vector_iterator() : _p(NULL) {}
		vector_iterator(value_type *ptr) : _p(ptr) {}
		vector_iterator(vector_iterator const &src) : _p(src._p) {}
		virtual ~vector_iterator() {}
		operator vector_iterator<value_type const>() const{ return (vector_iterator<value_type const>(_p)); }

		vector_iterator &operator=(const vector_iterator &src)
		{
			if (this != &src)
				this->_p = src._p;
			return (*this);
		}

		value_type *get_ptr() const
		{
			return (this->_p);
		}

		value_type *base() const
		{
			return (this->_p);
		}

		vector_iterator &operator++()
		{
			this->_p++;
			return (*this);
		}

		vector_iterator operator++(int)
		{
			vector_iterator res = *this;
			++(*this);
			return (res);
		}

		vector_iterator &operator--()
		{
			this->_p--;
			return (*this);
		}

		vector_iterator operator--(int)
		{
			vector_iterator it = *this;
			--(*this);
			return it;
		}

		value_type &operator[](int index)
		{
			return *(this->_p + index);
		}

		value_type *operator->()
		{
			return (this->_p);
		}

			bool operator==(const vector_iterator &other) const
		{
			bool b = this->_p == other._p;
			return (b);
		}

		bool operator!=(const vector_iterator &other) const
		{
			bool b = this->_p != other._p;
			return (b);
		}

		bool operator!=(const vector_iterator &other)
		{
			bool b = this->_p != other._p;
			return (b);
		}

		bool operator<(const vector_iterator &other) const
		{
			bool b = this->_p < other._p;
			return (b);
		}

		bool operator<=(const vector_iterator &other) const
		{
			bool b = this->_p <= other._p;
			return (b);
		}

		bool operator>(const vector_iterator &other) const
		{
			bool b = this->_p > other._p;
			return (b);
		}

		bool operator>=(const vector_iterator &other) const
		{
			bool b = this->_p >= other._p;
			return (b);
		}

		vector_iterator operator+(difference_type n) const
		{
			vector_iterator res = this->_p + n;
			return (res);
		}

		vector_iterator<T> operator-(difference_type n) const
		{
			vector_iterator res = this->_p - n;
			return (res);
		}

		difference_type operator-(const vector_iterator &rhs) const
		{
			difference_type res = this->_p - rhs._p;
			return (res);
		}

		difference_type operator+(const vector_iterator &rhs) const
		{
			difference_type res = this->_p + rhs._p;
			return (res);
		}

		vector_iterator<T> &operator+=(difference_type n)
		{
			this->_p += n;
			return *this;
		}

		vector_iterator<T> &operator-=(difference_type n)
		{
			this->_p -= n;
			return *this;
		}

		value_type &operator*() { return *this->_p; }
	};

	template <typename Iterator>
	vector_iterator<Iterator> operator+(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator> &it)
	{
		return (vector_iterator<Iterator>(it.base() + n));
	}

	template <typename Iterator>
	vector_iterator<Iterator> operator-(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator> &it)
	{
		return (vector_iterator<Iterator>(it.base() - n));
	}

	template <typename it1, typename it2>
	bool operator==(const vector_iterator<it1> &a, const vector_iterator<it2> &b)
	{
		bool res = a.get_ptr() == b.get_ptr();
		return (res);
	}

	template <typename it1, typename it2>
	bool operator != (const vector_iterator<it1> &a, const vector_iterator<it2> &b)
	{
		bool res = a.get_ptr() != b.get_ptr();
		return (res);
	}

	template <typename it1, typename it2>
	bool operator<(const vector_iterator<it1> &a, const vector_iterator<it2> &b)
	{
		bool res = a.get_ptr() < b.get_ptr();
		return (res);
	}

	template <typename it1, typename it2>
	bool operator<=(const vector_iterator<it1> &a, const vector_iterator<it2> &b)
	{
		bool res = a.get_ptr() <= b.get_ptr();
		return (res);
	}

	template <typename it1, typename it2>
	bool operator>(const vector_iterator<it1> &a, const vector_iterator<it2> &b)
	{
		bool res = a.get_ptr() > b.get_ptr();
		return (res);
	}

	template <typename it1, typename it2>
	bool operator>=(const vector_iterator<it1> &a, const vector_iterator<it2> &b)
	{
		bool res = a.get_ptr() >= b.get_ptr();
		return (res);
	}

	template <typename Iterator>
	std::ostream &operator<<(std::ostream &o, vector_iterator<Iterator> &src)
	{
		o << *src.get_ptr();
		return (o);
	}
}

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<iterator_type>::value_type value_type;
		typedef typename iterator_traits<iterator_type>::pointer pointer_type;
		typedef typename iterator_traits<iterator_type>::reference reference_type;
		typedef typename iterator_traits<iterator_type>::difference_type difference_type;
		typedef typename iterator_traits<iterator_type>::iterator_category iter_category;

	protected:
		iterator_type _ptr;

	public:
		reverse_iterator() : _ptr(NULL) {}
		reverse_iterator(iterator_type ptr) : _ptr(ptr) {}
		template <typename iter>
		reverse_iterator(const reverse_iterator<iter> &src) : _ptr(src.base()) {}

		virtual ~reverse_iterator() {}
		reverse_iterator &operator=(reverse_iterator const &src)
		{
			if (this != &src)
			{
				this->_ptr = src._ptr;
			}
			return (*(this));
		}

		iterator_type base(void) const
		{
			return (this->_ptr);
		}

		reference_type operator*() const
		{
			iterator_type it = this->_ptr;
			it--;
			return *it;
		}

		reverse_iterator &operator++()
		{
			this->_ptr--;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator it = *this;
			this->_ptr--;
			return it;
		}

		reverse_iterator &operator--()
		{
			this->_ptr++;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator it = *this;
			this->_ptr++;
			return it;
		}

		reverse_iterator &operator-=(difference_type n)
		{
			this->_ptr += n;
			return *this;
		}

		pointer_type operator->() const
		{
			return (&(operator*()));
		}

		reference_type operator[](difference_type n) const
		{
			return (*(this->_ptr - n - 1));
		}

		bool operator==(const reverse_iterator &other) const
		{
			return this->_ptr == other._ptr;
		}

		bool operator!=(const reverse_iterator &other) const { return this->_ptr != other._ptr; }
		bool operator<(const reverse_iterator &other) const { return this->_ptr > other._ptr; }
		bool operator<=(const reverse_iterator &other) const { return this->_ptr >= other._ptr; }
		bool operator>(const reverse_iterator &other) const { return this->_ptr < other._ptr; }
		bool operator>=(const reverse_iterator &other) const { return this->_ptr <= other._ptr; }

		reverse_iterator<Iterator> &operator+=(difference_type n)
		{
			this->_ptr -= n;
			return *this;
		}

		reverse_iterator<Iterator> operator-(difference_type n) const { return this->_ptr + n; }
		difference_type operator-(const reverse_iterator &rhs) const { return rhs._ptr - this->_ptr; }

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(this->_ptr - n));
		}
	};

	template <typename Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &it)
	{
		return (reverse_iterator<Iterator>(it.base() - n));
	}

	template <typename Iterator>
	reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &it)
	{
		return (reverse_iterator<Iterator>(it.base() + n));
	}

	template <class Iterator1, class Iterator2>
	bool operator==(reverse_iterator<Iterator1> const &lhs, reverse_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(reverse_iterator<Iterator1> const &lhs, reverse_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	bool operator<(reverse_iterator<Iterator1> const &lhs, reverse_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	bool operator<=(reverse_iterator<Iterator1> const &lhs, reverse_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	bool operator>(reverse_iterator<Iterator1> const &lhs, reverse_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename Iterator1, typename Iterator2>
	bool operator>=(reverse_iterator<Iterator1> const &lhs, reverse_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename Iterator>
	std::ostream &operator<<(std::ostream &o, reverse_iterator<Iterator> &rhs)
	{
		o << *rhs.base();
		return o;
	}
}

namespace ft
{
	template <typename T, typename node_pointer>
	class map_iterator
	{
	public:
		typedef T value_type;
		typedef value_type *pointer;
		typedef value_type &reference;
		typedef std::ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;

	protected:
		node_pointer _ptr;

	public:
		map_iterator() : _ptr(NULL) {}
		map_iterator(node_pointer ptr) : _ptr(ptr) {}
		map_iterator(map_iterator const &src) : _ptr(src._ptr) {}

		virtual ~map_iterator() {}

		map_iterator &operator=(map_iterator const &src)
		{
			if (this != &src)
				this->_ptr = src._ptr;
			return (*(this));
		}

		map_iterator &operator++()
		{
			increase();
			return (*(this));
		}
		map_iterator operator++(int)
		{
			map_iterator it = *this;
			++(*this);
			return (it);
		}
		map_iterator &operator--()
		{
			decrease();
			return (*(this));
		}
		map_iterator operator--(int)
		{
			map_iterator it = *this;
			--(*this);
			return (it);
		}

		reference operator*() const
		{
			return (this->_ptr->value);
		}

		pointer operator->() const
		{
			return (&(operator*()));
		}

		node_pointer get_node()
		{
			return (this->_ptr);
		}
		node_pointer get_node() const
		{
			return (this->_ptr);
		}
		operator map_iterator<const T, node_pointer>() const
		{
			return map_iterator<const T, node_pointer>(this->_ptr);
		}

		template <typename it2>
		bool operator==(const map_iterator<it2, node_pointer> &b) const
		{
			return (this->_ptr == b.get_node());
		}

		template <typename it2>
		bool operator!=(const map_iterator<it2, node_pointer> &b) const
		{
			return (this->_ptr != b.get_node());
		}
	private:
		void increase()
		{
			if (this->_ptr->right)
			{
				this->_ptr = this->_ptr->right;
				while (this->_ptr->left)
					this->_ptr = this->_ptr->left;
			}
			else
			{
				node_pointer tmp = this->_ptr;
				this->_ptr = this->_ptr->parent;
				while (this->_ptr->left != tmp)
				{
					tmp = this->_ptr;
					this->_ptr = this->_ptr->parent;
				}
			}
		}

		void decrease()
		{
			if (this->_ptr->left)
			{
				this->_ptr = this->_ptr->left;
				while (this->_ptr->right)
					this->_ptr = this->_ptr->right;
			}
			else
			{
				node_pointer tmp = this->_ptr;
				this->_ptr = this->_ptr->parent;
				while (this->_ptr->right != tmp)
				{
					tmp = this->_ptr;
					this->_ptr = this->_ptr->parent;
				}
			}
		}
	};

	template <typename One, typename Two>
	std::ostream &operator<<(std::ostream &o, map_iterator<One, Two> const &rhs)
	{
		o << *rhs.get_node();
		return o;
	}
}
