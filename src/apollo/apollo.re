
module InMemoryCache =
ApolloInMemoryCache.CreateInMemoryCache(
  {
    type dataObject;
    let inMemoryCacheObject = Js.Nullable.undefined;
  }
);

/* Create an HTTP Link */
let httpLink = ApolloLinks.createHttpLink(~uri="http://localhost:3010/graphql", ());

module Client =
ReasonApollo.CreateClient(
  {
    let apolloClient =
      ReasonApollo.createApolloClient(
        ~cache=InMemoryCache.cache,
        ~link=httpLink,
        ()
      );
  }
);