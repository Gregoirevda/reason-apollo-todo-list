import { log } from 'async';

// graphql-tools combines a schema string with resolvers.
const {makeExecutableSchema} = require('graphql-tools');

let todos = [
  { id: "1", active: true, title: "One"},
  { id: "2", active: false, title: "Two"}
];

// Construct a schema, using GraphQL schema language
const typeDefs = `
	input TodoInput {
		title: String!
    active: Boolean!
  }
    
	type Todo {
    id: ID!
    title: String!
    active: Boolean!
  }
    
  type Query {
    todos: [Todo!]!
  }

	type Mutation {
		deleteTodo(id: ID!): [Todo]
		toggleTodo(id: ID!): Todo!
		addTodo(title: String!, active: Boolean!): [Todo]
	}
`;

// Provide resolver functions for your schema fields
const resolvers = {
  Query: {
    todos: () => todos
  },
  Mutation: {
    deleteTodo: (_, {id}) => {
      todos = todos.filter(todo => todo.id !== id);
      return todos;
    },
    toggleTodo: (_, {id}) => {
      let resultTodo;
      todos = todos.map(todo => todo.id === id ? (resultTodo = todo && {...todo, active: !todo.active}) : todo)
      return resultTodo;
    },
    addTodo: (_, {title, active}) => {
      todos = [
        ...todos, 
        {
          id: "" + (parseInt(todos[todos.length - 1].id) + 1),
          title,
          active
        }];
        return todos;
    }
  }
};

exports.schema = makeExecutableSchema({
  typeDefs,
  resolvers,
});
