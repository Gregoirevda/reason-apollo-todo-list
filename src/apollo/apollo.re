
module InMemoryCache =
ApolloInMemoryCache.CreateInMemoryCache(
  {
    type dataObject;
    let inMemoryCacheObject = Js.Nullable.undefined;
  }
);

/* Create an HTTP Link */
module HttpLink =
ApolloLinks.CreateHttpLink(
  {
    let uri = "http://localhost:3010/graphql";
  }
);

module Client =
ReasonApollo.CreateClient(
  {
    let apolloClient =
      ReasonApollo.createApolloClient(
        ~cache=InMemoryCache.cache,
        ~link=ApolloLinks.from([|HttpLink.link|]),
        ()
      );
  }
);