
let inMemoryCache =
ApolloInMemoryCache.createInMemoryCache(());

/* Create an HTTP Link */
let httpLink = ApolloLinks.createHttpLink(~uri="http://localhost:3010/graphql", ());

let contextHandler = () => {
  let headers = {"headers": {"authorization": "123"}};
  headers;
};

let contextLink = ApolloLinks.createContextLink(contextHandler);

module Client =
ReasonApollo.CreateClient(
  {
    let apolloClient =
      ReasonApollo.createApolloClient(
        ~cache=inMemoryCache,
        ~link=ApolloLinks.from([|contextLink, httpLink|]),
        ()
      );
  }
);